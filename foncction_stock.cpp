#include<iostream>
using namespace std ;
#include"medicament.h"
#include"stockMed.h"
#include<vector>
void stockMed :: ajouter(medicament med , int ind) 
{
    medicament*q =new medicament(med) ;
    tab.insert(tab.begin()+ind , q) ;
}
stockMed:: stockMed() 
{
    string type ;
    int reference ;
    string nomCommercial ;
    float prixAchat ;
    int stock ;
    char rep ;
    int j1 ; int j2 ;int m1 ; int m2 ; int a1 ; int a2 ;
    medicament * med ; 
    do 
    {
        cout<<"<\n saisir un medicament :"<<endl ;
        cin>>type ;
        cin>>reference ;
        cin>>nomCommercial ;
        cin>>prixAchat ;
        cin>>stock ;
        cout<<"date de creation:"<<endl ;
        cin>>j1 ;
        cin>>m1 ;
        cin>>a1 ;
        cout<<"date expiration : "<<endl ;
        cin>>j2 ;
        cin>>m2 ;
        cin>>a2 ;
        med =new medicament(reference,type, nomCommercial,prixAchat, stock,j1,m1,a1,j2,m2,a2);
        tab.push_back(med) ;
        cout<<"\n rajouter ? "<<endl ;
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
void stockMed::afficher()
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
void stockMed::supprimer(int i)
{
    delete tab[i] ;
    tab.erase(tab.begin()+i) ;

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
        if(tab[i]->getReference()==r) 
            return true ;
        else return false ;
    }
}
void stockMed :: ajouter(medicament med, int ind)
{
    medicament* q=new medicament(med) ;
    tab.insert((tab.begin()+ind) , q) ;
} 