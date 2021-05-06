#include <string>
#include<iostream>
#include <ctime>
using namespace std ;

class date {
    int jour ;
    int mois ;
    int annee ;
    public :
    date(int,int ,int ) ;
    void saisir() ;
    void afficher() ;
    void setJour(int j){this->jour=j;}
    void setMois(int m){this->mois=m;}
    void setAnnee(int a){this->annee=a;}
    date local_date();
};

date :: date (int j=0,int m=0 , int a=0 )
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

date date::local_date() {
    time_t now = time(0);
    char* dt = ctime(&now);
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    this->setJour(gmtm->tm_mday);
    this->setMois(gmtm->tm_mon+1);
    this->setAnnee(gmtm->tm_year+1900);
    return *this;
}

void local_time()
{
    time_t curr_time= time(NULL);
	tm *tm_local = localtime(&curr_time);
	cout << "Current local time : " ;
    cout<< tm_local->tm_hour << ":" ;
    cout<< tm_local->tm_min << ":" ;
    cout<< tm_local->tm_sec;
}
