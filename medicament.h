#include<string.h>
#include<vector> 
class forme{
    string nom ;
    public :
    void saisir() ;
    void afficher() ;
    string getForme(){return nom ;}
    void set_Frome(string n){ nom=n ;}
};
class medicament {
    protected :
    int reference ;
    string type ;  // forme pharcaceutique ;
    string nomCommercial ;
    float prixVente = prixAchat +10% ;//client
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
    void setPrixAchat(float pa) { prixAchat=p ;} 
    int getStock(){ return stock;}
    void setNom(string  n ) { nomCommercial=n ;} 
    void setType(string t){ type =t ;} 
    void setStock(int s){ stock=s ;}
    void calcul_prixVente() ;
    medicament(int ,string ,string, float , int) 
    ~medicament(void) ;
    void afficher() ;

};
class pharmacie{
    vector<medicament*> tab ;
    public :
    pharmacie() ;
    void remplir() ;
    pharmacie(const pharmacie& );
    void ajouter(medicament, int=0) ;
    void supprimer(int=0) ;
    bool chercher_nom(medicament) ;
    int taille () {return tab.size();}
    void afficher() ;
    ~pharmacie(void) ;

};
// Classe stock qui herite de classe medicament
class stock: public medicament {
    protected : 
    int nombreTotal ;
    public :
    stock(medicament , int ) ;
    ~stock(void) ;
    static void afficherNombreTotal () ;
    int getStock() { return stock ;} ;
    void setStock (int s) {stock =s ;} ;
    void afficher () ;
    void Recherche_stock () ;
    void Supprimer_med();
    void Modifier_med();
    void Verification_med() ;
    void Verification_stock();
    void Commander_med();
};
