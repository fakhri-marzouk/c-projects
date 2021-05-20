#include<vector>
#include <ostream>
#include <istream>
#include<fstream>
#include <string>
#include<iostream>
using namespace std;

class date {
    public:
    int jour ;
    int mois ;
    int annee ;
    public :
    date(int=0,int=0 ,int=0 ) ;
    void saisirDate() ;
    void afficherDate() ;
    // ostream& operator<< (ostream&,date& );
    //istream& operator>> (istream&,date& ) ;
    int getJour(){return jour ;}
    int getMois(){return mois ;}
    int getAnnee(){return annee ;}

};

class medicament

{
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
    void setNom(string  n ) { nomCommercial=n ;}
    void setType(string t){ type =t ; }
    void setStock(int s){ stock=s ; }
    float calcul_prixVente() ;
    medicament(int=0 ,string="" ,string="", float=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0) ;
    void afficherMedicament() ;
    void saisirMedicament() ;
    friend ostream& operator<<(ostream&, medicament&) ;
    friend istream& operator>>(istream&,medicament&) ;   // cin et cout
    friend class achat;
    friend float calculAchat() ;
};

class stockMed{
    public:
    vector<medicament*> tab ;
    public :
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
    friend ostream& operator<<(ostream&, stockMed*) ;
    friend istream& operator>>(istream&,stockMed&) ;
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
     class stockCommande :public commande ,virtual public medicament , virtual public stockMed
     {
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
         float calculerTotalStock() ;
         static void creerFCommande(fstream &) ;
         static void remplirFStock(fstream& );
         static void afficherFStock(fstream &);
         friend ostream& operator<<(ostream& , stockCommande & );
         friend ostream& operator<<(ostream& , stockCommande *);
         friend istream& operator>>(istream& , stockCommande* );
         ~stockCommande();


     };
     class monnais
{
    public :
    float montant;

public:
    monnais(float Montant=0){
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
    friend void saisirAchat() ;
    friend float calculAchat() ;
    friend float calculTotal();
    friend class commande ;
    friend class stockCommande ;

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
         //float rechercherPA() ;
         //void afficheAchat() ;
//friend std::ostream& operator<<(ostream& , achat & ) ;
  //       friend  std::istream& operator>>(istream& , achat  & );
         ~achat(void);


     };


