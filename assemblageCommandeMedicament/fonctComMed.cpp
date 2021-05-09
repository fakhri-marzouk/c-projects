
#include <iostream>
#include<vector>
#include <ostream>
#include <istream>
#include<fstream>
#include <string>
#include"bibComMed.h"
using namespace std ;

void date :: saisirDate()
{
    cout<<"donner le jour"<<endl ;
    do {
        cin>>jour ;

    }
    while(jour<0 || jour>31) ;
    cout<<"\n donner le mois"<<endl ;
    do {
        cin>>mois;
    }while(mois<0 || mois>12) ;
    cout<<"\n donner l'annee"<<endl ;
    cin>>annee ;
}
void date :: afficherDate()
{
   cout<<"affichage date "<<endl ;
    cout<<jour<<"/"<<mois<<"/"<<annee<<endl ;
}
date :: date (int j,int m , int a )
{
        jour=j ;
        mois=m ;
        annee=a ;
}
ostream& operator<<(ostream& out , date& d)
{
    out<<"\n jour: "<<d.jour ;
    out<<"\n mois : "<<d.mois ;
    out<<"\n anne : "<<d.annee ;

}
istream& operator>>(istream& in , date& d)
{
    cout<<"donner le jour : "<<endl ;
    in>>d.jour ;
    cout<<"donner le mois : "<< endl ;
    in>>d.mois ;
    cout<<"donner l'annee :  "<<endl ;
    in>>d.annee ;
}

void medicament::saisirMedicament()
{
        cout<<"\n saisir un medicament :"<<endl ;
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
        date date_Creation ;
        date_Creation.saisirDate() ;
        cout<<"date expiration : "<<endl ;
        date date_Fin ;
        date_Fin.saisirDate() ;
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
    cout<<endl<<"date d'expiration";
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
    cout<<"donner le nombre de médicaments dans le stock :"<<endl ;
    in>>med.stock ;
    cout<<"la date de creation :"<<endl ;
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
    cout<<"ajouter "<<endl ;
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
void stockMed ::creer_fichier(fstream& f)
{
    f.open("stockmedicament.txt", ios::in | ios::out | ios::trunc ) ;
    if(! f.is_open()) exit(-1) ;
    cout<<"un fichier est cree"<<endl ;
}
void stockMed::remplir_fichier(fstream& f)
{

        stockMed sm ;
        f<<sm<<endl ;
}
void stockMed::afficher_fichier(fstream& f)
{
    char ch[100] ;
    stockMed sm ;
    f.seekg(0) ;
    while(1)
    {
        f.getline(ch,100) ;
        if(f.eof()) break ;
        cout<<ch<<endl ;
    }
}
stockMed:: stockMed()
{
    string type ;
    int refer ;
    string nomCommercial ;
    float prixAchat ;
    int stock ;
    char rep ;
    int j1 ; int j2 ;int m1 ; int m2 ; int a1 ; int a2 ;
    medicament * med ;
    do
    {
        cout<<"saisir un medicament :"<<endl ;
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
        cin>>j1 ;
        cin>>m1 ;
        cin>>a1 ;
        cout<<"date expiration : "<<endl ;
        cin>>j2 ;
        cin>>m2 ;
        cin>>a2 ;
        med =new medicament(refer,type,nomCommercial,prixAchat, stock,j1,m1,a1,j2,m2,a2);
        tab.push_back(med) ;
        cout<<"rajouter ? "<<endl ;
        cin>>rep ;
    }
    while(rep=='o'|| rep=='O');
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
    }
    }
}
bool stockMed::chercher_nom(string nom)
{
    for(int i=0;i<tab.size();i++)
    {
        if(tab[i]->getNom()==nom)
            return true ;
        else return false ;
    }
}
bool stockMed::chercher_ref(int r)
{
    for(int i=0;i<tab.size();i++)
    {
        if(tab[i]->getRefer()==r)
            return true ;
        else return false ;
    }
}
void stockMed :: ajouterMed(medicament med, int ind)
{
    medicament* q=new medicament(med) ;
    tab.insert((tab.begin()+ind) , q) ;
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

   // cout<<"donner le num de la commande "<< endl;
    //generate automatically
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
    for (int i=0 ; i<(this->tableCommande).size() ; i++)
    {

        cout<<"avant la somme \n"<<endl;
        somme+=tableCommande[i]->getPrix() ; //*(this->tableCommande)[i].qte ;
        cout<<"apres la somme \n"<<endl;
        cout<<"la somme est \n "<<somme;
    }
    cout<<"apres la boucle \n  "<< endl;
    return somme ;
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
/*stockCommande::stockCommande(const stockCommande & sc)
{

    for(int i=0 ;i<sc.tableStockCom.size() ; i++)
    {

        for (int j=0 ; j<tableCommande.size() ; j++)
        {
            /*this->tableStockCom[i].numCommande= sc.this->tableStockCom[i].numCommande ;
            this->tableStockCom[i].nbr=sc.this->tableStockCom[i].nbr ;

            medicament q=new medicament(*((sc.tableStockCom[i])[j]));

            tableCommande.push_back(q);
        }
        commande *p=new commande (*sc.tableStockCom[i]);
        tableStockCom.push_back(p) ;

}*/
void stockCommande::ajouterStockCommande()
 {   char rep ;
     do {


           cout<<"ajout de la  commande numero \t " << k  << " \t dans le stock"<< endl;
           commande *q=new commande ;
            q->saisirCommande();
            tableStockCom.push_back(q) ;
            for (int i=0 ; i<k ; i++)
            {
                tableStockCom[i]->numCommande=i+1 ;
            }
            k++ ;
            cout<<"voulez vous ajouter une auter commande?" << endl;
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

         //ajouter la fonction operator<< � la classe commande (fonction ami � la classe commandeStock)
    }
}
void stockCommande::supprimerCommande(int b) //b est l'indice du med dans le tableau du commande
{

         cout<<"avant la suppression "<< endl;
          for(int j=0 ; j< this->tableCommande.size() ;j++)
        {
            cout<<"dans le boucle de suppression"<< endl;
            delete ((this->tableStockCom[b])->tableCommande[j] );
            tableCommande.erase(tableCommande.begin()+j) ;
        }

        tableStockCom.erase(tableStockCom.begin()+b);

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
