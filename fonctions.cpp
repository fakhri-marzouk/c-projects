#include<string>
#include<iostream>
using namsepace std ;
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
void pharmacie::ajouter(medicament med , int ind) 
{
    medicament*med =new medicament(med) ;
    tab.insert(tab.begin()+ind , q) ;
}
pharmacie :: pharmacie() 
{
    string type;int reference;string nomCommercial;float prixAchat ;int stock ;char rep ;
    do 
    {
        cout<<"<\n saisir un medicament :"<<endl ;
        cin>>type ;
        cin>>reference ;
        cin>>nomCommercial ;
        cin>>prixAchat ;
        cin>>stock ;
        medicament * med =new medicament(type , reference, nomCommercial , prixAchat, stock);
        tab.push_back(med) ;
        cout<<"\n rajouter ?"<<endl ;
        cin>>rep ;
    }
    while(rep=='o'|| rep=='O');
}
pharmacie::pharmacie(const pharmacie&w )
{
    for(int i=0 ; i<w.tab.size();i++)
    {
        medicament *med=new medicament(*w.tab[i]) ;
        tab.push_back(med) ;
    }
}
void pharmacie::afficher()
{
    for(int i=0; i<tab.size() ;i++)
        tab[i]->afficher() ;
}
pharmacie::~pharmacie (int i)
{
    for(int i=0 ; i<tab.size();i++)
        delete tab[i] ;
    tab.clear() ;
}
void pharamacie::supprimer(int i)
{
    delete tab[i] ;
    tab.erease(tab.begin()+i) ;

}
bool cher
