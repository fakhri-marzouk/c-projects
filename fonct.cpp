#include "iostream"
#include"string"
#include"ostream"
#include"istream"
#include"vector"
#include"bib.h" 

/////////////////// commande///////////////////
using namespace std;

commande::commande(int a)
{
    numCommande=a ;
}
void commande::ajouterCommande()

{
    string rep ;
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
case "non" :
    {
        cout<<" OK! "<<endl;
    }

    } break ;
    default cout<<" s'il vous plaît , limitze vous sur noter choix /n voulez vous passer une comande 1)oui /n 1git status)non"<< endl;
}
float commande::calculerTotal(medicament &med )
{

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

}
void achat::saisirAchat()
{
    cout<<"voulez vous faire un achat"<< endl;
    cin>>rep ;
    switch(rep)
    {
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
}
