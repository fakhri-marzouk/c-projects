#include<vector> 
#include"date.h"
#include <ostream>
#include <istream>
#include<fstream>
#include <string>
class medicament {
    public :
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
    void setNom(string n ) { nomCommercial=n ;} 
    void setType(string t){ type =t ; } 
    void setStock(int s){ stock=s ; }
    float calcul_prixVente() ;
    medicament(int=0 ,string="" ,string="", float=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0) ;
    void afficherMedicament() ; 
    void saisirMedicament() ;
    friend ostream& operator<<(ostream&, medicament&) ;
    friend istream& operator>>(istream&,medicament&) ;   // cin et cout  
};
class stockMed{
    public :
    vector<medicament*> tab ;
    public :
     stockMed() ;
     ~stockMed(void) ;
    void remplirStock() ;
    stockMed(const stockMed& );
     void ajouterMed(medicament,int ) ;
    void supprimerMed_nom(string="") ;
    void supprimerMed_ref(int=0 ) ;
    void chercher_nom(string ) ;
    void chercher_ref(int ) ;
    int taille () {return tab.size();}
    void afficherStock() ;
    static void creer_fichier(fstream& ) ;
    static void remplir_fichier(fstream&, stockMed ) ;
    static void afficher_fichier(fstream& ) ;
    friend ostream& operator<<(ostream&, stockMed&) ; //ecrire à l'ecran 
    friend ostream& operator<<(ostream& ,stockMed *) ; // ecrire dans un fichier 
    friend istream& operator>>(istream&,stockMed&) ;  // lire du clavier
    friend istream& operator>>(istream& , stockMed*) ;//lire du fichier 
    void chercher_fichier_nom(string nom) ;
    void chercher_fichier_ref(int) ;
    void enregistrer() ;
    void recuperer() ;
    };
class commande :public medicament
{
public:
    int numCommande ;
    //date dateCommande;
    //int qte;
    int nbr ;
    static int m ;
    vector<medicament*> tableCommande ;
public :
      commande(int=0 ,int=0 ,int a=0 ,string b="" ,string c="", float d=0,int j1=0,int m1=0,int a1=0,int j2=0,int m2=0,int a2=0,int e=0);
      commande(const commande &);
      void setNumCo(int a){numCommande=a ;}
      int getNumCo(){return numCommande;}
      friend void saisirMedicament() ;
      void saisirCommande() ;
      void ajouterCommande();///doit etre une fonction amie � la classe medicament et on doit ajouter la la fonction rechercheMed � la classe med
      float calculerTotal() ;
      friend void afficherMedicament() ;
      void afficherCommande() ;
      int rechercherMedicament(int );
      static void afficherNumMed();

      ~commande(void) ;
     }; 
     class monnais 
{
    public :
    float montant;

public:
    monnais(float Montant=1000){
        this->montant=Montant;
    }
    float getMontant(){return this->montant;}
    void setMontant(float Montant){this->montant=Montant;}
    void ajouterMontant(){
        float m;
        cout<<"Donnez le montant à ajouter ";
        cin>>m;
        this->montant+=m;
    }
    void retirerMontant(){
        float m;
        cout<<"Donnez le montant à retirer ";
        cin>>m;
        this->montant-=m;
    }

    friend istream& operator>>(istream& in,monnais& m){
        in>>m.montant;
        return in;
    }
    friend ostream& operator<<(ostream& out,monnais& m){
        out<<m.montant;
            return out;
    } 
    
void afficherMontant()
{
    cout<<"\n le montant actuel est  ;"<< montant  <<endl;
}
    friend void saisirAchat() ;
    friend float calculAchat() ;
    friend float calculTotal();
    friend class commande ;
    friend class stockCommande ;

};
     
     class stockCommande :public commande , virtual public stockMed,public monnais 
     {   
         
         public:
         static int k ;
         vector<commande*> tableStockCom ;

     public:
         stockCommande() ;
         stockCommande(const stockCommande &) ;
         void afficherStockCo() ;
         void supprimerCommande(int);// on donne l'indice ici
         void supprimerMedicamentStock(string) ;
         void ajouterStockCommande() ;
         int rechercherCommande(int ) ;
         friend void afficherCommande();
        // friend void supprimerMed_nom(string="") ;
         static void afficherNumCom() ;
         float calculerTotalStock(monnais& ) ;
         static void creerFCommande(fstream &) ;
         static void remplirFStock(fstream& );
         static void afficherFStock(fstream &);
         friend ostream& operator<<(ostream& , stockCommande & );
         friend ostream& operator<<(ostream& , stockCommande *);
         friend istream& operator>>(istream& , stockCommande* );
         ~stockCommande();


     }; 
     
    
     class achat
     {
         medicament medAchat ;
        int qte ;
std::vector<medicament*> tabAchat;
     public :
         achat() ;
         achat(const achat &) ;
         void saisirAchat() ;
         float calculAchat();
         void afficherAchat();
         ~achat(void);
         float CalculAchat_fichier(monnais&) ;


     };
    