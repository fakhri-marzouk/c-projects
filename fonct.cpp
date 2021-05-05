<<<<<<< HEAD
#include "iostream"
#include"string"
#include"ostream"
#include"istream"
#include"vector"
#include"bib.h" 

/////////////////// commande///////////////////
using namespace std;

=======
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
>>>>>>> c1ede030fed757e67ea4ccaa0ecb02338509f3c2
commande::commande(int a)
{
    numCommande=a ;
}
void commande::ajouterCommande()

{
    string rep ;
<<<<<<< HEAD
    cout<<"voulez vous passer une commande 1\oui   2\non"<<endl;
    cin>>rep ;
    switch( 'rep' )
    {


case 'oui':
    {

       //medicament tabMed=new medicament ;   //saisie medicament
       /*cout<<"donner le num de la commande"<< endl;// objet static
       cin>>numCommande;*/
        cout<<"donner le nom de medicament"<< endl;
        cin>>med ;

        if med.Recherche_Med()== true  ////////////////////////////////////////
        {
            cout<<"donner la forme pharmaceutique "<< endl ;
        cin>>med.type ;
       /* cout<<"donner la classe du medicament "<< endl;
        cin>>med.cl ;*/
        cout<<"donner la quantité du medicament"<< endl;
        cin>>qte ;
        cout<<"donner le prix d'achat unitaire "<< endl;
        cin>>med.prixAchat ;

        }


        tab.push_back(med);
    } break;
=======
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
>>>>>>> c1ede030fed757e67ea4ccaa0ecb02338509f3c2
case "non" :
    {
        cout<<" OK! "<<endl;
    }

<<<<<<< HEAD
    } break ;
    default cout<<" s'il vous plaît , limitze vous sur noter choix /n voulez vous passer une comande 1)oui /n 1git status)non"<< endl;
=======
    }
>>>>>>> c1ede030fed757e67ea4ccaa0ecb02338509f3c2
}
float commande::calculerTotal(medicament &med )
{

<<<<<<< HEAD
     float somme=0.0 ;
    for (int i=0 , i<tab.size() ; i++)
    {
            somme=tab[i].prixAchat*tab[i].qte ;
    }
    return somme ;


}
void commande ::afficherCommande()
{
    for (int i=0 ; i<tab.size() ; i++)
    {
        cout<<tab[i] ;
    }
}

achat::achat()
{
  do
  {
      string rep ;
       cout<<"donner le medicamnet"<< endl;
       cin>>medAchat;
       cout <<"donner la quantité de cet medicament "<< endl;
       cin>>qte ;
       medicament* q= new medicament(medAchat);
       for(int i=0 ; i<qte ;i++)
       {
           tab1.push_back(q)
       }

       cout<<"\n rajouter "<<endl;
       cin>>rep ;

  }
  while(rep="oui "|| rep="OUI")
}
achat::achat(const & achat A)
{
    qte=A.qte ;
    medAchat=A.medAchat ;
    for (int i=0 ; i<A.tab1.size(); i++)
            {
               medicament * q=new medicament(*A.tab1[i]);
                tab1.push_back(q);
            }
=======

    for (int i=0 , i<nbr ; i++)
    {

    }

    cin>>med ;
    float s=0 ;


}
achat::achat(string ch , float f ,int a )
{
>>>>>>> c1ede030fed757e67ea4ccaa0ecb02338509f3c2

}
void achat::saisirAchat()
{
    cout<<"voulez vous faire un achat"<< endl;
    cin>>rep ;
    switch(rep)
    {
<<<<<<< HEAD
        case "oui":
     {
            achat a ;
            cin>>a ;
        }
        break;


      case "non" :
      {
          cout<<"OK! " <<endl ;
      }
      break ;
      default cout<<"le medicament n'existe pas"<< endl;
    }
}
float achat::calculachat()
{
     float s=0.0 ;
     for(int i=0 ; i<tab1.size() ; i++)
     {
        s=s+ rechercherPrix(tab1[i]) ; /////////il faut ajouter la fonction recherchePrix

     }
     cout<<" le total de l'achat est "<< s ;
=======
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

>>>>>>> c1ede030fed757e67ea4ccaa0ecb02338509f3c2
}
