#include<iostream>
using namespace std ;
#include"date.h"
date :: date (int j,int m , int a )
{
        jour=j ;
        mois=m ;
        annee=a ;
}
void date :: saisir()
{
    cout<<"donner le jour"<<endl ;
    cin>>jour ; 
    cout<<"\n donner le mois"<<endl ;
    cin>>mois; 
    cout<<"\n donner l'annee"<<endl ;
    cin>>annee ;
}
void date :: afficher()
{

    cout<<jour<<"/"<<mois<<"/"<<annee<<endl ;
}
ostream& operator<<(ostream& out , date& d)
{
    out<<"\n jour: "<<d.jour ;
    out<<"\n mois : "<<d.mois ;
    out<<"\n anne : "<<d.annee ;

}
istream& operator>>(istream& in , date& d)
{
    in>>d.jour ;
    in>>d.mois ;
    in>>d.annee ;
}