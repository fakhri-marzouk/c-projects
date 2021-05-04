#include<iostream>
using namespace std ;
#include"medicament.h"
#include"stockMed.h"
#include"date.h"
int main()
{
void stockMed :: ajouter(medicament med , int ind) 
{
    medicament *q =new medicament(med) ;
    tab.insert(tab.begin()+ind , q) ;
}
stockMed:: stockMed() 
{
    string type ;
    int reference;
    string nomCommercial;
    float prixAchat ;
    int stock ;
    char rep ;
    medicament * med ; 
    do 
    {
        cout<<"<\n saisir un medicament :"<<endl ;
        cin>>type ;
        cin>>reference ;
        cin>>nomCommercial ;
        cin>>prixAchat ;
        cin>>stock ;
        med =new medicament(type , reference, nomCommercial , prixAchat, stock);
        tab.push_back(med) ;
        cout<<"\n rajouter ?"<<endl ;
        cin>>rep ;
    }
    while(rep=='o'|| rep=='O');
}

stockMed::stockMed(const stockMed&w )
{
    for(int i=0 ; i<w.tab.size();i++)
    {
        medicament *med=new medicament(*w.tab[i]) ;
        tab.push_back(med) ;
    }
}
void stockMed::afficher()
{
    for(int i=0; i<tab.size() ;i++)
        tab[i]->afficher() ;
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
    tab.erease(tab.begin()+i) ;

}
bool stockMed::chercher_nom(medicament med)
{
    for(int i=0;i<tab.size();i++)
    {
        if(tab[i]->getNom()==med.getNom())
            return true ;
        else return false ;
    }
}
bool stockMed::chercher_ref(medicament med)
{
    for(int i=0;i<tab.size();i++)
    {
        if(tab[i]->getReference()==med.getReference())
            return true ;
        else return false ;
    }
}
void stockMed :: ajouter(medicament med, int ind)
{
    medicament* med=new medicament (med) ;
    tab.insert(tab.begin()+ind , med) ;
} 

ostream& operator<<(ostream& out , medicament& med)
{
    out<<"\n réference :"<<med.reference ;
    out<<"\n Type : "<<med.type ;
    out<<"\n nom Commercial:"<<med.nomCommercial ;
    out<<"\n prix vente: "<<med.prixVente ;
    out<<"\n prix achat: "<<med.prixAchat ;
    out<<"\n stock: "<<med.stock ;
    out<<"\n date Creation :"<<med.date_Creation ;
    out<<"\n date Fin  :"<<med.date_Fin ;
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
    in>>med.date_Creation ;
    in>>med.date_Fin ;
    return in ; 
}
return 0 ;
}