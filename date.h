class date {
    int jour ;
    int mois ;
    int annee ;
    public :
    date(int=0,int=0 ,int=0 ) ;
    void saisir() ;
    void afficher() ;
    int getJour(){return jour ;}
    int getMois(){return mois ;}
    int getAnnee(){return annee ;}
};