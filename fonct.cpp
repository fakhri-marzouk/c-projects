#include <iostream>
#include<string>
#include<ostream>
#include<istream>
#include"bib.h"


using namespace std;
medicament::medicament(string nomCh , string nomCo)
{
    nomChimique=nomCh;
    nomCommercial=nmCo ;
}
commande::commande(int a)
{
    numCommande=a ;
}
void commande::ajouterCommande()

{
    string rep ;
    cout<<"voulez vous ajouter un medicament au commande 1\oui   2\non"<<endl;
    cin>>rep ;
    switch(rep )
    {


case "oui":
    {

        medicament *q =new medicament ;   //saisie medicament
        cout<<"donner le medicament"<< endl;
        cin>>*q ;
        tab.push_back(q);
    }
case "non" :
    {
        cout<<" OK! "<<endl;
    }

    }
}
float commande::calculerTotal(medicament &med )
{


    for (int i=0 , i<nbr ; i++)
    {

    }

    cin>>med ;
    float s=0 ;


}
achat::achat(string ch , float f ,int a )
{

}
void achat::saisirAchat()
{
    cout<<"voulez vous faire un achat"<< endl;
    cin>>rep ;
    switch(rep)
    {
        case (oui)
        {
            cout<<"donner le nom commercial , le prix d'achat et la quantite que vous voulez l'acheter "<<endl;
            cin>>nomCommercial ;
            cin>>prixAchat ;
            cin>>qte;
}
        }
    }
      case (non)
      {
          cout<<"OK! " <<endl ;
      }
}
float achat::calculachat()
{

}
