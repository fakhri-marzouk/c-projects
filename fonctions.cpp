#include<iostream>
using namespace std ;
#include"medicament.h" 
#include"date.h" 
#include<string>
void medicament::saisirMedicament()
{
    int j1 ; int j2 ;int m1 ; int m2 ; int a1 ; int a2 ;
    cout<<"\n saisir un medicament"<<endl ;
        cin>>type ;
        cin>>reference ;
        cin>>nomCommercial ;
        cin>>prixAchat ;
        cin>>stock ;
        cout<<"date de creation:"<<endl ;
        cin>>j1 ;
        cin>>m1 ;
        cin>>a1 ;
        date date_Creation(j1,m1,a1) ;
        cout<<"date expiration : "<<endl ;
        cin>>j2 ;
        cin>>m2 ;
        cin>>a2 ;
        date date_Fin(j2,m2,a2) ;
}
medicament :: medicament(int r ,string t, string n , float pa , int s,int j1,int m1 , int a1, int j2 , int m2 , int a2)
{
    reference=r ;
    type=t ;
    nomCommercial=n ;
    prixAchat=pa ;
    stock=s ;
    prixVente=calcul_prixVente() ;
    date date_Creation(j1,m1,a1) ;
    date date_Fin(j2,m2,a2) ;
}
float medicament :: calcul_prixVente()
{
    float prixVente ;
    prixVente=prixAchat+((prixAchat*7)/100) ;
    return prixVente ;
}
void medicament :: afficherMedicament()
{
    cout<<"la reference est :"<<reference<<endl ;
    cout<<"le type est :"<<type<<endl ;
    cout<<"le nom commercial :"<<nomCommercial<<endl ;
    cout<<"le stock est :"<<stock<<endl ;
    cout<<"le prix est :"<<prixVente<<endl ;
    cout<<"date de creation :";
    date_Creation.afficher() ;
    cout<<endl<<"date d'expiration";
    date_Fin.afficher() ;

}
ostream& operator<< (ostream& out , medicament& med)
{
    out<<"\n réference :"<<med.reference ;
    out<<"\n Type : "<<med.type ;
    out<<"\n nom Commercial:"<<med.nomCommercial ;
    out<<"\n prix vente: "<<med.prixVente ;
    out<<"\n prix achat: "<<med.prixAchat ;
    out<<"\n stock: "<<med.stock ;
    // out<<"\n date Creation"<<med.date_Creation 
   
    return out ;
}
istream& operator>>(istream& in, medicament& med)
{
    in>>med.reference ;
    in>>med.type ;
    in>>med.nomCommercial ;
    in>>med.prixVente ;
    in>>med.prixAchat ;
    in>>med.stock ;
    return in ; 
}