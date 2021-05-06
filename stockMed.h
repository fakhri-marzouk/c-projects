#include"medicament.h"
#include<vector>
class stockMed{
    vector<medicament*> tab ;
    public :
    stockMed() ;
    void remplir() ;
    stockMed(const stockMed& );
    void ajouter(medicament, int=0) ;
    void supprimer(int=0) ;
    bool chercher_nom(string ) ;
    bool chercher_ref(int ) ;
    int taille () {return tab.size();}
    void afficher() ;
    ~stockMed(void) ;
};