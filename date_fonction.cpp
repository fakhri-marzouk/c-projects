#include"date.h"
date :: date (int j , int m , int a )
{
    jour=j ;
    mois=m;
    annee=a ;
}
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

    cout<<jour<<"/"<<mois<<"/"<<annee<<endl ;
}
ostream& operator<<(ostream& out , date& d)
{
    out<<d.jour<<"/"<<d.mois<<"/"<<d.annee<<endl ;

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
