#include"comptes.h"

int main(){
    while(1){
        cout<<"voulez-vous s'authentifier ou créer un compte?"<<endl;
        cout<<"1 : authentifer"<<endl;
        cout<<"2 : créer un compte"<<endl;
        cout<<"Votre choix : ";
        int choix;
        cin>> choix;
        system("pause<0");
        break;
        if (choix==1){
            
        }
        else if (choix==2){
            cout<<"Choisissez le type du compte à créer :"<<endl;
            cout<<"1 : client"<<endl;
            cout<<"2 : fournisseur"<<endl;
            cout<<"3 : employé"<<endl;
            cout<<"4 : gérant"<<endl;
            cout<<"Votre choix : ";
            cin>> choix;
            //creation de compte
            if (choix==1){
                client p;
            }
            else if (choix==2){
                fournisseur p;
            }
            else if (choix==3){
                employe p;
            }
            else if (choix==4){
                gerant p;
            }
            personne p;
            p.saisir();

        }

    /*string pseudo;
    string nom;
    string prenom;
    int CIN;
    string adresse;
    string mail;
    long tel;*/
        
    }
    return 0;
}