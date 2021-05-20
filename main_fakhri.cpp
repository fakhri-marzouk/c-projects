#include"iostream"
#include"ostream"
#include"istream"
#include<string>
#include <stdlib.h>
using namespace std ;
#include"fonctions.cpp"
#include<fstream>
int main()
{    
    monnais m;  
    m.afficherMontant(); 


    achat a ; 

    float  res=a.CalculAchat_fichier(m) ;
    cout<<res<<endl ; 
    m.afficherMontant() ;

    cout<<m.montant; 
    stockCommande sc ;  
    sc.ajouterStockCommande() ; 
    sc.calculerTotalStock(m);   
    m.afficherMontant();

    /*stockCommande sc ; 
    sc.ajouterCommande(); 
    sc.calculerTotalStock(); 
    m.afficherMontant(); 
    //////************************pour le fournisseur *****************************/////
    

    /* cout<<" la menu principal est "<< endl;

    fstream fCommande ;
    commande com ;
    //medicament med() ;
    int  rep ;
    stockCommande sc ;
    cout<<"indiquez votre choix  :\n "<<endl;
    cout<<"1)Remplir le stock  \n "<<endl;
    cout<<"2)Gerer le stock \n"<<endl;
    cout<<"3)afficher les commandes \n"<< endl;

    cin >>rep ;
    switch (rep )
    {
        //////////----------remplir une commande-------/////////
    case 1 :
        {
            
            int r ;
            sc.ajouterStockCommande() ;
            cout<<"vous voulez calculer le total \n 1)oui \n 2)non :"<< endl ;
            cin>>r ;
            if (r==1) { cout<<"le total de vos commandes est "<< sc.calculerTotalStock()<< endl;}
            else {cout<<"d'accord"<< endl;}

        }
                 //////////--------gerer le stock ---------///////////
   case 2 :
    {   int a ;
        cout<<"vous voulez : \n1) annuler une commande \n 2)ajouter une commande \n 3)chercher une commande \n "<< endl ;
        cin>>a ;
        switch (a)
        {

        case 1 :
            {
            int num ;
           // stockCommande sc;
           system("cls");
            cout<<"donner le num du commande "<< endl;
            cin>>num ;
           int b= sc.rechercherCommande(num) ;
           if (b!=-1 )
           {
               sc.supprimerCommande(num) ;
              cout<<"la commande est supprim�e"<< endl;
           }
           else cout<<"la commande n'existe pas"<< endl ;
            }
        case 2 :
            {
                sc.ajouterStockCommande() ;
            }
        case 3 :
            {
                int num ;
                cout<<"donner le num de la commande"<< endl ;
                cin>>num ;
                int b=sc.rechercherCommande(num ) ;
                if( b!=-1)
                {
                    cout<<"le commande existe"<< endl;
                    sc.afficherCommande();
                }
                //cout<<"le commande n'existe pas"<< endl;
            }

        } //default : cout<<"erreur"<< endl;
    }
        case 3 :
            {
                sc.afficherStockCo() ;
            }
            default: break ;
    }*/
    
   /* stockMed sm ;
    fstream f ;
    etiquette :
    cout<<"veuillez choisir votre choix : "<<endl ;
    cout<<"1 : ajouter un medicament "<<endl ;
    cout<<"2 : afficher un medicament "<<endl ;
    cout<<"3 : chercher un medicament par reference "<<endl ;
    cout<<"4 : chercher un medicament par nom "<<endl ;
    cout<<"5 : supprimer un medicament par reference "<<endl ;
    cout<<"6 : supprimer un medicament par nom "<<endl ;
    cout<<"7 : chercher un medicament dans le fichier "<<endl ;
    cout<<"8 : tapez 0 pour sortir "<<endl ;
    cout<<"9 : donner votre choix :"<<endl ;
    int choix ; 
    cin>> choix ;
    switch (choix)
    {
    case 1 :{

            sm.remplirStock() ;  
            //stockMed::creer_fichier(f);   
            stockMed::remplir_fichier(f,sm) ;
            goto etiquette ;
    }
        break;
    case 2 :{
            //sm.afficherStock() ;
            //sm.enregistrer() ;
            //sm.recuperer() ;
            sm.afficher_fichier(f) ;
            goto etiquette ;
    }
    case 3 :{
        cout<<"donner la reference de medicament cherchee:"<<endl;
        int r ;
        cin>>r ;
        sm.chercher_ref(r);
         goto etiquette ;
    }
    case 4 :{
        cout<<"donner le nom de medicament cherche :" <<endl ;
        string nom ;
        cin>>nom ;
        sm.chercher_nom(nom) ;
         goto etiquette ;
    }
    case 5 :{
        cout<<"donner la reference de medicament a supprime:"<<endl ;
        int r ;
        cin>>r ;
        sm.supprimerMed_ref(r);
         goto etiquette ;
    }
    case 6:{
        cout<<"donner le nom de medicament a supprime :"<<endl ;
        string nom ;
        cin>>nom ;
        sm.supprimerMed_nom(nom) ;
         goto etiquette ;
    }
    case 7 :
    {
        
        cout<<"donner le nom de medicament cherche :"<<endl ;
        string nom ;
        cin>>nom ;
        //sm.recuperer() ;
        sm.chercher_fichier_nom(nom) ;
         goto etiquette ;
    }
    case 8:
    {
        cout<<"donner la reference de medicament :"<<endl ;
        int n ;
        cin>>n ;
        sm.chercher_fichier_ref(n) ;
    }
    default:
    {
         cout<<"merci pour l'utilisation :) "<<endl ;
         break; }
    }
    f.close() ;*/
    return 0 ;
    }
