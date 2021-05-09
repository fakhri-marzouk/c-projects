#include<iostream>
using namespace std ;
#include"medicament.h" 
#include<string>
#include<vector>
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
