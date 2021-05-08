#ifndef BIBCOM_H_INCLUDED
#define BIBCOM_H_INCLUDED

#include <iostream>
#include<string>
#include<ostream>
#include<istream>
#include<vector>
#include<iostream>
using namespace std ;
class date
 {
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
    friend class medicament ;

};


class medicament
{
    public:
    int refer ;
    string type ; // forme pharcaceutique ;
    string nomCommercial ;
    float prixVente ; // prixAchat +10%
    float prixAchat ; //fournisseur
    int stock ;
    date date_Creation ;
    date date_Fin ;
    public :
    int getReference(){ return refer ;}
    string getNom() { return nomCommercial ;}
    float getPrix() { return prixAchat ;}
    string getType(){ return type ;}
    void setReference(int r) { refer=r ; }
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
    friend void afficheDate() ;
};




class commande :public medicament
{
protected :
    int numCommande ;
    //date dateCommande;
    //int qte;
    int nbr ;
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
      void supprimerCommande(int ) ;
      int rechercherMedicament(int );
      ~commande(void) ;
     };





#endif // BIBCOM_H_INCLUDED
