#include <string>
#include<iostream>
#include <ctime>
using namespace std;

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


date local_date() {
    date d;
    time_t now = time(0);
    char* dt = ctime(&now);

   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   d.setJour(gmtm->tm_mday);
   d.setMois(gmtm->tm_mon+1);
   d.setAnnee(gmtm->tm_year+1900);
   return d;
}

void local_time()
{
    time_t curr_time= time(NULL);

	tm *tm_local = localtime(&curr_time);
    cout<< tm_local->tm_hour << ":" ;
    cout<< tm_local->tm_min << ":" ;
    cout<< tm_local->tm_sec;
	
}

void EnTete_open() {
    system("cls");
    system("color 2e");
    printf("\xc9");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
    printf("\xbb  ");
    printf("\n\xba ");
    local_time();
    printf(" \xba Central PHARMACY \xba    ");
    local_date().afficher();
    printf("    \xba       OPEN      ");
    printf("\xba   Tunis  \xba\n");
    printf("\xc8");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
    printf("\xbc");
    printf("\n\n");
}
void EnTete_closed() {
    system("cls");
    system("color 2e");
    printf("\xc9");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
    printf("\xbb  ");
    printf("\n\xba ");
    local_time();
    printf(" \xba Central PHARMACY \xba    ");
    local_date();
    printf("    \xba      CLOSED     ");
    printf("\xba   Tunis  \xba\n");
    printf("\xc8");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
    printf("\xbc");
    printf("\n\n");
}
