#include<iostream>
#include<string>
#include<sstream>
#include <stdlib.h>
using namespace std ;
#include"medicament.h"
#include<fstream>
#include<vector>

void medicament::saisirMedicament()
{
        int j1 ;int m2; int j2 ; int a1 ; int a2 ;int m1 ;
        cout<<"\n saisir un medicament avec medicament  :"<<endl ;
        cout<<"donner la reference :"<<endl ;
        cin>>refer ;
        cout<<"donner le type :"<<endl ;
        cin>>type ;
        cout<<"donner le nomCommercial"<<endl ;
        cin>>nomCommercial ;
        cout<<"donner le prix de vente"<<endl ;
        cin>>prixAchat ;
        cout<<"donner le nombre de medicament dans le stock :"<<endl ;
        cin>>stock ;
        cout<<"date de creation:"<<endl ;
        cout<<"donner le jour : "<<endl ;
    do {
        cin>>j1 ;
    }
    while(j1<0 || j1>31) ;
    cout<<"donner le mois : "<<endl ;
    do {
        cin>>m1 ; 
    }while(m1<0 || m1>12) ;   
    cout<<"donner l'annee : " <<endl ;    
    cin>>a1 ;
    date date_Creation(j1,m1,a1);
        cout<<"date expiration : "<<endl ;
        cout<<"donner le jour : "<<endl ;
     do {

        cin>>j2 ;
    }
    while(j2<0 || j2>31) ;
    cout<<"donner le mois : "<<endl ;
    do {
        cin>>m2; 
    }while(m2<0 || m2>12) ;       
    cout<<"donner l'annee :"<<endl ;
    cin>>a2 ;
        date date_Fin(j2,m2,m2) ;
        prixVente=calcul_prixVente() ;
        
}
medicament :: medicament(int r ,string t, string n ,float pa , int s, int j1,int m1 , int a1, int j2 , int m2 , int a2):date_Creation(j1,m1,a1),date_Fin(j2,m1,a1)
{
    refer=r ;
    type=t ;
    nomCommercial=n ;
    prixAchat=pa ;
    stock=s ;
    prixVente=calcul_prixVente() ;
}
float medicament :: calcul_prixVente()
{
    float prix ;
    prix=prixAchat+((prixAchat*7)/100) ;
    return prix ;
}
void medicament :: afficherMedicament()
{
    cout<<"la reference est :"<<refer<<endl ;
    cout<<"le type est :"<<type<<endl ;
    cout<<"le nom commercial :"<<nomCommercial<<endl ;
    cout<<"le stock est :"<<stock<<endl ;
    cout<<"le prix est :"<<prixVente<<endl ;
    cout<<"date de creation :" ;
    date_Creation.afficherDate() ;
    cout<<endl<<"date d'expiration :";
    date_Fin.afficherDate() ;
}
ostream& operator<< (ostream& out , medicament& med)
{
    out<<"\n réference :"<<med.refer ;
    out<<"\n Type : "<<med.type ;
    out<<"\n nom Commercial:"<<med.nomCommercial ;
    out<<"\n prix vente: "<<med.prixVente ;
    out<<"\n stock: "<<med.stock ;
    out<<"\n date Creation"<<med.date_Creation ;
    out<<"\n date expiration"<<med.date_Fin ;
    return out ;
}
istream& operator>>(istream& in, medicament& med)
{
    cout<<"donner la reference :"<<endl ;
    in>>med.refer ;
    cout<<"donner le type : "<<endl ;
    in>>med.type ;
    cout<<"donner le nom commercial :"<<endl ;
    in>>med.nomCommercial ;
    cout<<"donner le prix de vente"<<endl ;
    in>>med.prixVente ;
    cout<<"donner le nombre de medicaments dans le stock :"<<endl ;
    in>>med.stock ;
    cout<<"la date de creationnnnn :"<<endl ;
    in>>med.date_Creation ;
    cout<<"la date d'expiration : "<<endl ;
    in>>med.date_Fin   ;
    return in ; 
}

istream& operator>>(istream& in , stockMed& sm)
{
 char rep ;
 do
 {
    cout<<"saisir un medicament avec in sm  "<<endl ;
    medicament* med=new medicament() ;
    in>>*med; 
    sm.tab.push_back(med) ;
    cout<<"ajouter ? "<<endl ;
    cin>>rep ;
 }while( rep=='o' || rep=='O') ;
 return in ;
}
ostream& operator<<(ostream& out , stockMed& sm )
{
    for(int i=0 ; i<sm.tab.size(); i++)
        {  
            out<<*sm.tab[i]<<endl ;
        }
    return out ;
}
istream& operator>> (istream& in , stockMed * sm)  // lire aprartir du fichier 
{
    in.seekg(0) ;
    for(int i=0;i<sm->tab.size();i++)
    {
        if(in.eof()) break ;
        medicament * med=new medicament() ;
        med->saisirMedicament() ;
        //in>>*med ; // appel de operator de la classe medicament 
        sm->tab.push_back(med) ;
    }
    return in ;
}
ostream& operator<<(ostream& out , stockMed * sm)   // ecrire dans un fichier 
{
    for(int i=0 ;i<sm->tab.size();i++)
    {
        out<<*sm->tab[i]<<endl ;
    }
    return out ; 
}
void stockMed ::creer_fichier(fstream& f)
{
    f.open("stockmedicament.txt", ios::in | ios::out | ios::app) ;
    if(! f.is_open()) exit(-1) ;
    cout<<"un fichier est cree"<<endl ;
}
void stockMed::remplir_fichier(fstream& f, stockMed sm)
{
    f.open("stockmedicament.txt", ios::in | ios::out | ios::app) ;
    if(! f.is_open()) exit(-1) ;
    for(int i=0;i<sm.tab.size();i++)
        f<<&sm<<endl ;
}
void stockMed::afficher_fichier(fstream& f)
{
    //ifstream f ; // i == in 
    f.open("stockmedicament.txt",ios::in ) ; // overture en mode lecture seulement 
    if(! f.is_open()) exit(-1) ;
    //medicament med ;
    char ch[200] ;
    f.seekg(0) ;
    while(1)
    {
        f.getline(ch,100) ;
        //f>>med ;
        if(f.eof()) break ;
        cout<<ch<<endl ;
    }
}
stockMed:: stockMed() 
{
}
void stockMed::remplirStock()
{
    medicament * med ;
    char rep ;
    string type ;
    int refer ;
    string nomCommercial ;
    float prixAchat ;
    int stock ;
    int j1 ; int j2 ;int m1 ; int m2 ; int a1 ; int a2 ;
    do 
    {
        cout<<"saisir un medicament avec stockMed :"<<endl ;
        cout<<"donner la reference: "<<endl ;
        cin>>refer ;
        cout<<"donner le type de medicament :"<<endl ;
        cin>>type ;
        cout<<"donner le nom commercial : "<<endl ;
        cin>>nomCommercial ;
        cout<<"donner le prix d'achat"<<endl ;
        cin>>prixAchat ;
        cout<<"donner le stock de medicament"<<endl ;
        cin>>stock ;
        cout<<"date de creation:"<<endl ;
        cout<<"donner le jour : "<<endl ;
        do {

        cin>>j1 ;
        }
        while(j1<0 || j1>31) ;
        cout<<"donner le mois : "<<endl ;
        do {
        cin>>m1; 
    }while(m1<0 || m1>12) ;   
    cout<<"donner l'annee : "<<endl ;     
    cin>>a1 ;
        cout<<"date expiration : "<<endl ;
        cout<<"donner le jour : "<<endl ;
        do {

        cin>>j2 ;
    }
    while(j2<0 || j2>31) ;
    cout<<"donner le mois : "<<endl ;
do {
        cin>>m2; 
    }while(m2<0 || m2>12) ;  
    cout<<"donner l'annee : "<<endl ;     
     cin>>a2 ;
        med =new medicament(refer,type,nomCommercial,prixAchat, stock,j1,m1,a1,j2,m2,a2);
        tab.push_back(med) ;
        cout<<"rajouterrrrrr ? "<<endl ;
        cin>>rep ;
    }
    while(rep=='o'|| rep=='O');
}
void stockMed::ajouterMed(medicament med,int ind)
{
    medicament* q=new medicament(med) ;
    tab.insert(tab.begin()+ind,q) ;
} 

stockMed::stockMed(const stockMed& w)
{
    for(int i=0 ; i<w.tab.size();i++)
    {
        medicament*med=new medicament(*w.tab[i]) ;
        tab.push_back(med) ;
    }
}
void stockMed::afficherStock()
{
    for(int i=0; i<tab.size() ;i++)
        tab[i]->afficherMedicament() ;
}
stockMed::~stockMed()
{
    for(int i=0 ; i<tab.size();i++)
        delete tab[i] ;
    tab.clear() ;
}
void stockMed::supprimerMed_ref(int r)
{
    for(int i=0;i<tab.size();i++)
    {
        if(tab[i]->getRefer()==r )  
            { 
                delete tab[i] ;
                tab.erase(tab.begin()+i) ;
                cout<<"medicament supprime !"<<endl ;
            }
    }
}
void stockMed::supprimerMed_nom(string n)
{
    for(int i=0;i<tab.size();i++)
    {
        if(tab[i]->getNom()==n)
            { 
            delete tab[i] ;
            tab.erase(tab.begin()+i) ;
            cout<<"medicament supprime !"<<endl ;
            }
    }
}
void stockMed::chercher_nom(string nom)
{
    for(int i=0;i<tab.size();i++) 
    {
        string n ;
        n=tab[i]->getNom() ;
        int res=n.compare(nom) ;
        if(res==0)
            cout<<"le medicament existe encore ! "<<endl ;
    }
}
void stockMed::chercher_ref(int a)
{
    for(int i=0;i<tab.size();i++)
      {  
        int r =tab[i]->getRefer();
        if(r==a) 
            cout<<"le medicament existe encore ! "<<endl ; 
        }
        cout<<"medicament n'existe pas ! "<<endl ;
}
void stockMed::chercher_fichier_nom(string nom)
{
    char ch[101];
    stockMed sm ;
    ifstream fin;
    fin.open("stockmedicament.txt");
    fin.getline(ch,100,'\n');
    bool existe=0;
    while(!fin.eof())
    {
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,':');
        fin.getline(ch,100,'\n');
        string b(ch);
        if (b==nom)
        {
            cout<<"medicament trouve "<<endl;//goto et1 ;
            existe=1;
            break;
        } 
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');   
    }
    if (existe==0){
    cout<<"medicament n'existe pas "<<endl ;
    }
}
    
void stockMed::chercher_fichier_ref(int ref)
{
    char ch[101];
    stockMed sm ;
    ifstream fin;
    fin.open("stockmedicament.txt");
    fin.getline(ch,100,'\n');
    bool existe=0;
    while(!fin.eof())
    {
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,':');
        fin.getline(ch,100,'\n');
        int b =stoi(ch);
        if (b==ref)
        {
            cout<<"medicament trouve "<<endl;//goto et1 ;
            existe=1;
            break;
        } 
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');   
    }
    if (existe==0){
    cout<<"medicament n'existe pas "<<endl ;
    }
}
void stockMed::enregistrer() // ou bien remplir 
{
    fstream f ;
    f.open("stockmedicament.txt", ios::in | ios::out | ios::app ) ;
    if(! f.is_open()) exit(-1) ;
    for(int i=0;i<tab.size();i++)
    {
        f<<*tab[i]<<endl ;
    }
    f.close() ;
}
void stockMed::recuperer()  // ne marche pas 
{
    fstream f ;
    f.open("stockmedicament.txt" , ios::in | ios::out | ios::app);
    if(! f.is_open()) exit(-1) ;
    while(1)
    {
        if(f.eof()) break ;
        medicament * med=new medicament() ;
        f>>*med ;
        tab.push_back(med) ;
    }
    f.close() ;
}
int stockCommande::k=0;
void stockCommande::afficherNumCom()
{
    cout<<"\n le numero de la commande suivante est  ;"<< k <<endl;
}
int commande:: m=0 ;
void commande::afficherNumMed()
{
    cout<<"\n le numero du medicament est : "<< m << endl ;
}
commande::commande(int ac,int bc , int a ,string b ,string c, float d,int j1,int m1,int a1,int j2,int m2,int a2,int e):medicament(a , b , c , d , j1 , m1 , a1 , j2 , m2, a2, e)
{
    numCommande=ac ;
    nbr=bc ;
    m++;

}
commande::commande(const commande & c)
{
    numCommande= c.numCommande ;
    nbr=c.nbr ;
    for(int i=0 ; i<nbr ; i++)
    {
        medicament *q=new medicament(*c.tableCommande[i]) ;
        tableCommande.push_back(q) ;
    }

}

void commande::saisirCommande()//refaire
{

   
    cout<<"donner le nombre de medicaments "<< endl ;
    cin>>nbr ;
    for(int i=0 ;i<nbr ;i++)
    {
        {
            medicament *q=new medicament ;
            q->saisirMedicament();
            (this->tableCommande).push_back(q);
        }
}
}

float commande::calculerTotal()//monnais
{

    float somme=0.0 ;
    for (int i=0 ; i<this->tableCommande.size() ; i++)
    {
        somme+=tableCommande[i]->prixVente ;
    }
    return somme ;
     //monnais m ;
/*float montant=m.getMontant() ;
   float  montant-=somme;*/
}

void commande ::afficherCommande()
{

    for (int i=0 ; i<(this->tableCommande).size() ; i++)
    {
        cout<< "affichage de la commande : \n"<<endl;
        (this->tableCommande[i])->afficherMedicament() ;
    }
}

int commande::rechercherMedicament(int  b)
{
    for(int i=0 ; i<nbr ; i++)
    {
        if ((this->tableCommande[i]->getRefer())==b)
            return (i+1) ;
    }

    return -1 ;
}



commande::~commande()
{
    for(int j=0 ; j<nbr ;j++)
        {
            delete tableCommande[j] ;
        }
        tableCommande.clear() ;
}
stockCommande::stockCommande()
{
    {
        k ++ ;
    }
}

istream& operator>>(istream& in , stockCommande* sc)
{
    in.seekg(0) ;
    int nbr;
 cout<<"donner le nombre de medicaments "<< endl ;
    cin>>nbr ;
    for(int i=0 ;i<nbr ;i++)
    {
        {
            medicament *q=new medicament ;
            q->saisirMedicament();
            (sc->tableCommande).push_back(q);
        }
}
 return in ;
}

ostream& operator<<(ostream& out , stockCommande * sc)
{
    for(int i=0 ; i<sc->tableStockCom.size(); i++)
        {  for(int j=0 ; j<sc->tableCommande.size() ; j++)

            out<<*(sc->tableStockCom[i]->tableCommande[j])<<endl ;
        }
    return out ;
}
void stockCommande::creerFCommande(fstream& f)
{
    f.open("path", ios::in | ios::out | ios::trunc ) ;
    if(! f.is_open()) exit(-1) ;
    cout<<"un fichier est cree"<<endl ;
}
void stockCommande::remplirFStock(fstream& f)
{
        stockCommande sc ;
        f<<&sc<<endl ;
}
void stockCommande::afficherFStock(fstream& f)
{
    char ch[100] ;
    stockCommande sc ;
    f.seekg(0) ;
    while(1)
    {
        f>>&sc ;
        if(f.eof()) break ;
        cout<<&sc<<endl ;
    }
}
void stockCommande::ajouterStockCommande()
 {   char rep ;
     do {


           cout<<"ajout de la  commande numero \t " << k  << " \t dans le stock"<< endl;
           commande *q=new commande ;
            q->saisirCommande();
            tableStockCom.push_back(q) ;
            for (int i=0 ; i<this->tableStockCom.size(); i++)
            {
                tableStockCom[i]->numCommande=i+1 ;
            }
            k++ ;
            cout<<"voulez vous ajouter une autre commande?" << endl;
            cin>> rep ;

     }
     while(rep=='o'|| rep=='O');


 }

void stockCommande::afficherStockCo()
{

    cout<<"affichage du stock"<< endl;
    for(int i=0 ;i<this->tableStockCom.size() ; i++)

    {

    (this->tableStockCom[i])->afficherCommande();
    }
}
void stockCommande::supprimerCommande(int b) //b est l'indice du com dans le vecteur  du commande
{
          for(int j=0 ; j< this->tableStockCom.size() ;j++)
        {
            delete ((this->tableStockCom[b-1])->tableCommande[j] );
        }
        tableStockCom.erase(tableStockCom.begin()+b-1);

     cout<<"la commande est annul�e"<< endl;

}
int stockCommande::rechercherCommande(int b)
{
    for(int i=0 ; i<this->tableStockCom.size() ; i++)
    {
        if (this->tableStockCom[i]->numCommande==b)
            return (i+1);
    }
    return -1 ;
}

float stockCommande::calculerTotalStock(monnais & ab)
{
    float s=0.0 ;

    for (int i=0 ; i<tableStockCom.size() ;i++)
    {
        s+=this->tableStockCom[i]->calculerTotal() ;
    }
    return s ; 
    ab.montant-=s ;  
    cout<<"on a fait le retrait de votre argent"<<endl; 
}
stockCommande:: ~stockCommande()
{
    for(int i=0 ;i<tableStockCom.size() ;i++)
    {
        for(int j=0 ; j<tableCommande.size() ;j++)
        {
            delete (this->tableStockCom[i])->tableCommande[j] ;
        }
        tableCommande.clear() ;
    }tableStockCom.clear();
}
achat::achat()
{
}
achat::achat(const achat &  A)
{
    qte=A.qte ;
    medAchat=A.medAchat ;
    for (int i=0 ; i<A.tabAchat.size(); i++)
            {
               medicament * q=new medicament(*A.tabAchat[i]);
                tabAchat.push_back(q);
            }

}
void achat::saisirAchat()
{
    int rep ;
    cout<<"voulez vous faire un achat ? \n 1)oui \n 2)non \n  "<< endl;
    cin>>rep ;
    if(rep=1)
    {
     {
         int nb ;
           cout<<"donner le nombre de med que vous voulez achetés"<< endl;
           cin>> nb ;
            for(int i=0 ;i<nb ;i++)

        {
            medicament *q=new medicament ;
            q->saisirMedicament();
            (this->tabAchat).push_back(q);
        }
}

    }
}
float achat::calculAchat()
{
     float s=0.0 ;
     for(int i=0 ; i<this->tabAchat.size() ; i++)
     {
       float m=(tabAchat[i]->getPrix()) ;
       s+=m ;/////////il faut ajouter la fonction recherchePrix
     }
     cout<<" le total de l'achat est "<< s ;
     monnais mon ;
     mon.montant+=s;  
      cout<<"le prix est ajouté au montant avec succée"<<endl;
}
void achat::afficherAchat()
{
    for(int i=0 ; i<this->tabAchat.size(); i++)
    {
        tabAchat[i]->afficherMedicament() ;
    }
}

achat::~achat()
{

}
float achat::CalculAchat_fichier(monnais& ab)
{
    float res =0 ;
    int rep ;
    cout<<"voulez vous faire un achat ? \n 1)oui \n 2)non \n  "<< endl;
    cin>>rep ;
    if(rep=1)
     {
         int nb ;
           cout<<"donner le nombre de med que vous voulez achetés"<< endl;
           cin>> nb ;
            for(int i=0 ;i<nb ;i++)

        {
            string nom ;
            cout<<"doner le nom de medicament :"<<endl ;
            cin>>nom ;
            char ch[101];
        stockMed sm ;
        ifstream fin;
        fin.open("stockmedicament.txt");
        fin.getline(ch,100,'\n');
        bool existe=0;
        while(!fin.eof())
    {
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,':');
        fin.getline(ch,100,'\n');
        string b(ch);
        if (b==nom)
        {
            cout<<"medicament trouve "<<endl;//goto et1 ;
            fin.getline(ch,100,'\n');
            fin.getline(ch,100,':');
            fin.getline(ch,100,'\n');
           // res=std::stof(ch) ;
            stringstream bb;
            bb<<ch;
            bb>>res;
            existe=1;
            break;
        } 
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');   
    }
    if (existe==0){
    cout<<"medicament n'existe pas "<<endl ;
    }

        }
}   
     ab.montant+=res;  
     cout<<"le prix est ajouté au montant avec succée"<<endl;
     return res;
    
 }
    


/*std::ostream& achat::operator<<(ostream& out , achat  & a)
      {   for (int i=0 ; i<a.tab1.size();i++)
      {


          out<<a.medAchat <<endl;

      }
      return out ;

      }
      istream& achat::operator<<(istream& in , achat & a)
      {   for (int i=0 ; i<a.tab1.size();i++)
      {
          in<<a.medAchat <<endl;

      }
      return in ;

      }*/
