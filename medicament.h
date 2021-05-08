#include<vector> 
#include"date.h"
#include <ostream>
#include <istream>
#include<fstream>
#include <string>
class medicament {
    protected :
    int refer ;
    string type ; // forme pharcaceutique ;
    string nomCommercial ; 
    float prixVente ; // prixAchat +10% 
    float prixAchat ; //fournisseur
    int stock ;
    date date_Creation ;
    date date_Fin ;
    public :
    int getRefer(){ return refer ;} 
    string getNom() { return nomCommercial ;} 
    float getPrix() { return prixAchat ;} 
    string getType(){ return type ;} 
    void setRefer(int r) { refer=r ; } 
    void setPrixAchat(float pa) { prixAchat=pa ;} 
    int getStock(){ return stock; }
    void setNom(string  n ) { nomCommercial=n ;} 
    void setType(string t){ type =t ; } 
    void setStock(int s){ stock=s ; }
    float calcul_prixVente() ;
    medicament(int=0 ,string="" ,string="", float=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0) ;
    void afficherMedicament() ; 
    void saisirMedicament() ;
    friend ostream& operator<<(ostream&, medicament&) ;
    friend istream& operator>>(istream&,medicament&) ;   // cin et cout  
};
#include<vector>
class stockMed{
    vector<medicament*> tab ;
    public :
    stockMed() ;
    void remplirStock() ;
    stockMed(const stockMed& );
    void ajouterMed(medicament, int=0) ;
    void supprimerMed_nom(string="") ;
    void supprimerMed_ref(int=0 ) ;
    bool chercher_nom(string ) ;
    bool chercher_ref(int ) ;
    int taille () {return tab.size();}
    void afficherStock() ;
    ~stockMed(void) ;
    static void creer_fichier(fstream& ) ;
    static void remplir_fichier(fstream& ) ;
    static void afficher_fichier(fstream& ) ;
    friend ostream& operator<<(ostream&, stockMed&) ;
    friend istream& operator>>(istream&,stockMed&) ; 
};
