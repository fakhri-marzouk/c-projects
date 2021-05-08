#include <iostream>
#include"bibCom.h"
using namespace std;

int main()
{

   // medicament med ;
   // med.saisirMedicament() ;
    //med.afficherMedicament();
    commande c ;
    c.saisirCommande();
    c.afficherCommande();
    float f=c.calculerTotal() ;
    cout<<f<<endl;


    cout << "Hello world!" << endl;
    return 0;
}
