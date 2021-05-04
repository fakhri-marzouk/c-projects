#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
class commande
{
protected :
    int numCommande ;
    date dateCommande;
    int qte;
    vector<medicament*> tab ;
public :
      commande(int=0 );
      commande(const commande &);
      void setNumCo(int a){numCommande=a ;}
      int getNumCo(){return numCommande;}
      void ajouterCommande();///doit etre une fonction amie à la classe medicament et on doit ajouter la la fonction rechercheMed à la classe med
      float calculerTotal() ;
      //void consulterCommande(medicament&) ;
      void afficherCommande() ;
      void annulerMedicament(medicament) ;


      ~commande(void) ;
     };

     class achat
     {
         medicament medAchat ;
         int qte ;
         vector<medicament*> tab1;
         date dateAchat ;
     public :
         achat(medicament ,  int=0) ;
         achat(const &)
         void saisirAchat() ;
         float calculachat();
         float rechercherPA() ;
         //void afficheAchat() ;
         friend operator& operator<<(ostream& , achat const & ) ;
          friend operator& operator>>(istream& , achat const & );
         ~achat(void);


     };
      ostream& operator<<(ostream& out , achat const & a)
      {   for (int i=0 ; i<a.tab1.size();i++)
      {
          out<<a.medAchat <<endl;

      }
      return out ;

      }
      istream& operator<<(istream& in , achat const & a)
      {   for (int i=0 ; i<a.tab1.size();i++)
      {
          in<<a.medAchat <<endl;

      }
      return in ;

      }

#endif // BIB_H_INCLUDED
