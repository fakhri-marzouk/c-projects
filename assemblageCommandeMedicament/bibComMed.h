#ifndef BIBCOMMED_H_INCLUDED
#define BIBCOMMED_H_INCLUDED
#ifndef BIBCOMMANDE4_H_INCLUDED
#define BIBCOMMANDE4_H_INCLUDED
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
      friend saisirMedicament() ;
      void saisirCommande() ;
      void ajouterCommande();///doit etre une fonction amie � la classe medicament et on doit ajouter la la fonction rechercheMed � la classe med
      float calculerTotal() ;
      friend void afficherMedicament() ;
      void afficherCommande() ;
      int rechercherMedicament(int  );
      static void afficherNumMed();
      ~commande(void) ;
     };
     class stockCommande :public commande ,virtual public medicament
     {
         static int k ;
         vector<commande*> tableStockCom ;

     public:
         stockCommande() ;
         stockCommande(const stockCommande &) ;
         void afficherStockCo() ;
         void supprimerCommande(int);// on donne l'indice ici
         void supprimerMedicamentStock(medicament) ;
         void ajouterStockCommande() ;
         int rechercherCommande(int ) ;
         friend void afficherCommande();
         static void afficherNumCom() ;
         ~stockCommande();


     };


#endif // BIBCOMMANDE4_H_INCLUDED



#endif // BIBCOMMED_H_INCLUDED
