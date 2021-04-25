#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED
class commande
{
protected :
    int numCommande ;
    date dateCommande;
    float total ;
    vector<medicament*> tab ;
public :
      commande(int=0 );
      commande(const commande &);
      void setNumCo(int a){numCommande=a ;}
      int getNumCo(){return numCommande;}
      void ajouterCommande(medicament&);
      float calculerTotal(medicament& ) ;
      void consulterMedicament(medicament&) ;
      void afficherCommande() ;
      void annulerMedicament(medicament) ;


      ~commande(void) ;
     };

     class achat
     {
         string nomCommercial;
         float prixAchat ;
         int qte ;
         vector<medicament *> ;
         date dateAchat ;
     public :
         achat(string=0 , float=0.0 , int=0 , date ) ;
         void saisirAchat() ;
         float calculachat();
         void afficheAchat() ;
         ~achat(void);


     };
     class medicament
     {
         string nomChimique ;
         string nomCommercial ;

     public :
         medicament(string , string ) ;

         friend ostream& operator<<(ostream& , medicament&) ;
         friend istream& operator>>(istream& , medicament& );
         friend float calculerTotal(medicament& );
     };




#endif // BIB_H_INCLUDED
