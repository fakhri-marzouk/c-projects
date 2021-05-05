#include<iostream>
using namsepace std ;
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
void date :: afficher(msg)
{
    cout<<jour<<"/"<<mois<<"/"<<annee<<endl ;
}