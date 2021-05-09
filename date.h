#include<iostream>
#include<ostream>
#include<istream>
class date {
    public: 
    int jour ;
    int mois ;
    int annee ;
    public :
    date(int,int,int ) ;
    void saisirDate() ;
    void afficherDate() ;
    //ostream& operator<< (ostream&,date& ) ;
    //istream& operator>> (istream&,date& ) ;
    int getJour(){return jour ;}
    int getMois(){return mois ;}
    int getAnnee(){return annee ;}
    
};

date :: date (int j,int m , int a )
{
        jour=j ;
        mois=m ;
        annee=a;
}
void date :: saisirDate()
{
    cout<<"donner le jour"<<endl ;
    cin>>jour ; 
    cout<<"\n donner le mois"<<endl ;
    cin>>mois; 
    cout<<"\n donner l'annee"<<endl ;
    cin>>annee ;
}
void date :: afficherDate()
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