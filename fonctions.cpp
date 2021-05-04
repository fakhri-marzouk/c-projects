#include<string>
#include<iostream>
#include<vector>
using namespace std ;
#include"medicament.h"
#include"date.h"
void medicament :: calcul_prixVente()
{
    float prixVente ;
    prixVente=prixAchat+((prixAchat*7)/100) ;

}
medicament :: medicament(int r ,string t, string n , float pa , int s)
{
    reference=r ;
    type=t;
    nomCommercial=n ;
    prixAchat=pa ;
    stock=s ;
    calcul_prixVente() ;
    date_Creation.saisir() ;
    date_Fin.saisir() ;
}
void medicament :: afficher()
{
    cout<<"la reference est :"<<reference<<endl ;
    cout<<"le type est :"<<type<<endl ;
    cout<<"le nom commercial :"<<nomCommercial<<endl ;
    cout<<"le stock est :"<<stock<<endl ;
    cout<<"le prix est :"<<prixVente ;
    date_Creation.afficher() ;
    date_Fin.afficher() ;
}
medicament::~medicament()
{

}
