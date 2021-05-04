#include<string.h>
#include<vector> 
#include"date.h"
class forme{
    string nom ;
    public :
    void saisir() ;
    void afficher() ;
    string getForme(){return nom ;}
    void setForme(string n){ nom=n ;}
};
class medicament {
    protected :
    int reference ;
    string type ;  // forme pharcaceutique ;
    string nomCommercial ;
    float prixVente  ; // prixAchat +10% 
    float prixAchat ; //fournisseur
    int stock ;
    date date_Creation ;
    date date_Fin ;
    public :
    int getReference(){ return reference ;} 
    string getNom() {return nomCommercial ;} 
    float getPrix() { return prixAchat ;} 
    string getType(){ return type ;} 
    void setReference(int r) { reference=r ; } 
    void setPrixAchat(float pa) { prixAchat=pa ;} 
    int getStock(){ return stock;}
    void setNom(string  n ) { nomCommercial=n ;} 
    void setType(string t){ type =t ;} 
    void setStock(int s){ stock=s ;}
    void calcul_prixVente() ;
    medicament(int ,string ,string, float , int) ;
    ~ medicament(void) ;
    void afficher() ; 
    friend ostream& operator<<(ostream&, medicament&) ;
    friend istream& operator>>(ostream&,medicament& ) ;   // cin et cout  
};
