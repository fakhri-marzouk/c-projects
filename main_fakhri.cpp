#include"iostream"
#include"ostream"
#include"istream"
using namespace std ;
#include"fonctions.cpp"
#include<fstream>
#include<string>
int main()
{
    stockMed sm ;
     fstream f ;
     f<<&sm ;
    etiquette :
    cout<<"veuillez choisir votre choix : "<<endl ;
    cout<<"1 : ajouter un medicament "<<endl ;
    cout<<"2 : afficher un medicament "<<endl ;
    cout<<"3 : chercher un medicament par reference "<<endl ;
    cout<<"4 : chercher un medicament par nom "<<endl ;
    cout<<"5 : supprimer un medicament par reference "<<endl ;
    cout<<"6 : supprimer un medicament par nom "<<endl ;
    cout<<"7 : tapez 0 pour sortir "<<endl ;
    cout<<"8 : donner votre choix :"<<endl ;
    int choix ; 
    cin>> choix ;
    switch (choix)
    {
    case 1 :{
        
            stockMed::creer_fichier(f) ;
            stockMed::remplir_fichier(f) ;
            goto etiquette ;
    }
        break;
    case 2 :{
            sm.afficherStock() ;
            goto etiquette ;
    }
    case 3 :{
        cout<<"donner la reference de medicament cherché :"<<endl;
        int r ;
        cin>>r ;
        string res =sm.chercher_ref(r);
        cout<<res<<endl ;
         goto etiquette ;
    }
    case 4 :{
        cout<<"donner la nom de medicament cherché :" <<endl ;
        char * nom ;
        cin>>nom ;
        string res =sm.chercher_nom(nom) ;
        cout<<res<<endl ;
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
    default:
        break;
    }
    
    f.close() ;
    return 0 ;
}