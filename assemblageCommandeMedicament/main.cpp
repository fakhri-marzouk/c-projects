#include <iostream>
#include<vector>
#include <ostream>
#include <istream>
#include<fstream>
#include <string>
#include"bibComMed.h"
using namespace std;

int main()
{
     stockCommande scom ;
     scom.ajouterStockCommande() ;
     scom.afficherStockCo();
     int ind=scom.rechercherCommande(2) ;
     cout<<"l'indice est"<< ind <<endl;
     scom.supprimerCommande(1) ;
     scom.afficherStockCo() ;
     fstream f ;
     stockMed::creer_fichier(f) ;
     stockMed::remplir_fichier(f) ;
     stockMed::afficher_fichier(f) ;
     f.close() ;
     return 0 ;
     cout << "Hello world!" << endl;
     return 0;
}
