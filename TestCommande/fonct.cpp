#include <iostream>
#include<string>
#include<ostream>
#include<istream>
#include<vector>
#include"bibCom.h"
using namespace std ;



void medicament::saisirMedicament()
{
    int j1 ; int j2 ;int m1 ; int m2 ; int a1 ; int a2 ;
    cout<<"\n saisir un medicament"<<endl ;
        cin>>refer ;
        cin>>type ;
        cin>>nomCommercial ;
        cin>>prixAchat ;
        cin>>stock ;
        cout<<"date de creation:"<<endl ;
        date date_Creation;
        date_Creation.saisirDate() ;
        cout<<"date expiration : "<<endl ;
        date date_Fin ;
        date_Fin.saisirDate() ;
        prixVente=calcul_prixVente() ;

}
float medicament :: calcul_prixVente()
{
    float prix ;
    prix=prixAchat+((prixAchat*7)/100) ;
    return prix ;
}
medicament :: medicament(int r ,string t, string n , float pa , int s,int j1,int m1 , int a1, int j2 , int m2 , int a2):date_Creation(j1,m1,a1),date_Fin(j2,m1,a1)
{
    refer=r ;
    type=t ;
    nomCommercial=n ;
    prixAchat=pa ;
    stock=s ;
    prixVente=calcul_prixVente() ;
}

void medicament :: afficherMedicament()
{
    cout<<"la reference est :"<<refer<<endl ;
    cout<<"le type est :"<<type<<endl ;
    cout<<"le nom commercial :"<<nomCommercial<<endl ;
    cout<<"le stock est :"<<stock<<endl ;
    cout<<"le prix est :"<<prixVente<<endl ;
    cout<<"date de creation :";
    date_Creation.afficherDate() ;
    cout<<endl<<"date d'expiration";
    date_Fin.afficherDate() ;

}
ostream& operator<< (ostream& out , medicament& med)
{
    out<<"\n réference :"<<med.refer ;
    out<<"\n Type : "<<med.type ;
    out<<"\n nom Commercial:"<<med.nomCommercial ;
    out<<"\n prix vente: "<<med.prixVente ;
    out<<"\n prix achat: "<<med.prixAchat ;
    out<<"\n stock: "<<med.stock ;
    return out ;
}
istream& operator>>(istream& in, medicament& med)
{
    in>>med.refer ;
    in>>med.type ;
    in>>med.nomCommercial ;
    in>>med.prixVente ;
    in>>med.prixAchat ;
    in>>med.stock ;
    return in ;
}


commande::commande(int ac,int bc , int a ,string b ,string c, float d,int j1,int m1,int a1,int j2,int m2,int a2,int e):medicament(a , b , c , d , j1 , m1 , a1 , j2 , m2, a2, e)
{
    numCommande=ac ;
    nbr=bc ;

}
commande::commande(const commande & c)
{
    numCommande= c.numCommande ;
    nbr=c.nbr ;
    for(int i=0 ; i<nbr ; i++)
    {
        medicament *q=new medicament(*c.tableCommande[i]) ;
        tableCommande.push_back(q) ;
    }

}



void commande::saisirCommande()//refaire
{
    int nbr ;
    cout<<"donner le num de la commande "<< endl;
    cin>>numCommande ;//generate automatically
    cout<<"donner le nombre de medicaments "<< endl ;
    cin>>nbr ;
    for(int i=0 ;i<tableCommande.size() ;i++)
    {

        medicament *q=new medicament ;
        q->saisirMedicament();
        (this->tableCommande).push_back(q);

        }

}

float commande::calculerTotal()//monnais
{

    float somme=0.0 ;
    for (int i=0 ; i<nbr ; i++)
    {
        somme+=tableCommande[i]->prixAchat ; //*(this->tableCommande)[i].qte ;
        cout<<somme;
    }
    cout<<"la somme est "<< endl;
    return somme ;
}

void commande ::afficherCommande()
{
    cout<< "affichage du table commande : \n"<<endl;
    for (int i=0 ; i<(this->tableCommande).size() ; i++)
    {
        this->tableCommande[i]->afficherMedicament() ;
    }
}







int commande::rechercherMedicament(int b)
{
    for(int i=0 ; i<nbr ; i++)
    {
        if (tableCommande[i]->refer==b)
            return i ;
    }
    return -1 ;
}



commande::~commande()
{
    for(int j=0 ; j<nbr ;j++)
        {
            delete tableCommande[j] ;
        }
        tableCommande.clear() ;
}
date :: date (int j,int m , int a )
{
        jour=j ;
        mois=m ;
        annee=a ;
}
void date :: saisirDate()
{
    cout<<"donner le jour"<<endl ;
    cin>>jour ;
    cout<<"\n donner le mois"<<endl ;
    cin>>mois;
    cout<<"\n donner l'annee"<<endl ;
    cin>>annee ;
}
void date :: afficherDate()
{
    cout<<"affichage date "<<endl ;
    cout<<jour<<"/"<<mois<<"/"<<annee<<endl ;
}
ostream& operator<<(ostream& out , date& d)
{
    out<<"\n jour: "<<d.jour ;
    out<<"\n mois : "<<d.mois ;
    out<<"\n anne : "<<d.annee ;

}
istream& operator>>(istream& in , date& d)
{
    in>>d.jour ;
    in>>d.mois ;
    in>>d.annee ;
}


/*
stockCommande::stockCommande(const stockCommande & sc)
{

    for(int i=0 ;i<sc.stockCom.size() ; i++)
    {
        commande *q=new commande (*sc.stockCom[i]);
        stockCom.push_back(q);
    }
}
void stockCommande::affichageStockCo()
{
    for(int i=0 ;i<stockCom.size() ; i++)
    {
        stockCom[i].afficherCommande(); //ajouter la fonction operator<< � la classe commande (fonction ami � la classe commandeStock)
    }
}
void stockCommande::supprimerMedicamentStock(medicament & Med )
{
    for(int i=0 ; i<stockCom.size() ; i++)
    {
        for(int j=0 ; j<nbr ; j++)
            if (Med.nomCommercial==tab[i][j].nomCommercial)
        {
            delete stockCom[i][j];
            tabCom[i].erase(tabCom.begin()+j) ;
            cout<<"le medicamment est supprim� du stock "<<endl;
        }
        cout<<"le medicamment n'existe pas dans le stock" <<endl ;
    }
}
 void stockCommande::ajoutStockCommande() ;
 {
      commande *q=new commande ;
            q->saisirCommande();  ///////////////ajouter la fonction saisirCommande

            tabCom.push_back(q) ;
 }
stockCommande:: ~stockCommande()
{
    for(int i=0 ;i<tabCom.size() ;i++)
    {
        for(int j=0 ; j<nbr ;j++)
        {
            delete tabCom[i][j] ;
        }
        tabCom[i].clear() ;
    }tabCom.clear()
}
int stockCommande::rechercherCommande(int b)
{
    for(int i=0 ; i<nbr ; i++)
    {
        if (tabCom[i].refer==b)
            return i ;
    }
    return -1 ;
}
void stockCommande::supprimerCommande(int b) //b est l'indice du med dans le tableau du commande
{
     if (b<nbr )
     {
         tabCom[b].erase(tabCom.begin()+i ) ;
     }
     cout<<"la commande est annul�e"<< endl;



}

achat::achat()
{
  do
  {
      string rep ;
       cout<<"donner le nom de la medicamnet"<< endl;
       cin>>medAchat;
       cout <<"donner la quantit� de cette medicament "<< endl;
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
        s=s+ getPrix(tab1[i]) ; /////////il faut ajouter la fonction recherchePrix

     }
     cout<<" le total de l'achat est "<< s ;
}

void medicament :: calcul_prixVente()
{
    float prixVente ;
    prixVente=prixAchat+((prixAchat*7)/100) ;

}
class caisse
{

};

std::ostream& achat::operator<<(ostream& out , achat  & a)
      {   for (int i=0 ; i<a.tab1.size();i++)
      {


          out<<a.medAchat <<endl;

      }
      return out ;

      }
      istream& achat::operator<<(istream& in , achat & a)
      {   for (int i=0 ; i<a.tab1.size();i++)
      {
          in<<a.medAchat <<endl;

      }
      return in ;

      }
*/

