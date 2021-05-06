#include<string.h>
#include<vector> 
#include"date.h"
class medicament {
    protected :
    int reference ;
    string type ; // forme pharcaceutique ;
    string nomCommercial ; 
    float prixVente ; // prixAchat +10% 
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
    int getStock(){ return stock; }
    void setNom(string  n ) { nomCommercial=n ;} 
    void setType(string t){ type =t ; } 
    void setStock(int s){ stock=s ; }
    float calcul_prixVente() ;
    medicament(int=0 ,string="" ,string="", float=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0) ;
    void afficherMedicament() ; 
    void saisir() ;
    friend ostream& operator<<(ostream&, medicament& ) ;
    friend istream& operator>>(istream&,medicament& ) ;   // cin et cout  
};
