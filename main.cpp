#include "comptes.h"
#include "date.h"
#include "monnais.h"
#include <iostream>
#include<string>
#include<iostream>
#include"bib.h"

using namespace std;

int main(){
    comptes tabComptes;
    personnes tabPersonnes;
    personne p;
    compte c;
    int choix=-1;
    while(1){
        bool loggedIn=0;
        cout<<"voulez-vous s'authentifier ou créer un compte?"<<endl;
        cout<<"1 : s'authentifier"<<endl;
        cout<<"2 : créer un compte"<<endl;
        cout<<"Votre choix : ";
        cin>> choix;
        system("pause<0");
        switch (choix){
        case 1:{
            cout<<"Authentification : "<<endl;
            cin>>c;
            if(tabComptes.verifier(c)){
                loggedIn=1;
                personne p=tabPersonnes.getPersonne(c);
            }
            break;
        }
        case 2:{
            cout<<"Choisissez le type du compte à créer :"<<endl;
            cout<<"1 : client"<<endl;
            cout<<"2 : fournisseur"<<endl;
            cout<<"3 : employé"<<endl;
            cout<<"4 : gérant"<<endl;
            cout<<"Votre choix : ";
            cin>> choix;
            //creation de compte
            switch(choix){
                case 1:{
                    p.setType("client");
                    break;
                }
                case 2:{
                    p.setType("fournisseur");
                    break;
                }
                case 3:{
                    p.setType("employe");
                    break;
                }
                case 4:{
                    p.setType("gerant");
                    break;
                }
                default:{
                    p.setType("");
                    cout<<"choix non existant"<<endl;
                    break;
                }
            }
            //fin switch pour choisir type
            if(p.getType()!=""){
                //creation d'une personne
                cout<<"création d'un compte"<<endl;
                string Pseudo="";
                string Password="";
                do{
                    cout<<"Donnez un pseudo :"<<endl;
                    cin>>Pseudo;
                    c.setPseudo();
                }while(tabComptes.find(c)!=-1);
                cin>>Password;
                c.setPass();
                tabComptes.ajouter(c);
            p.saisir();
                tabPersonnes.ajouter(p);
            }
        default:
            break;
        }
            }
            
        if(loggedIn){
            if (p.getType()=="client"){
                //affichage pour client
                cout<<"bonjour cher client "<<p.getNom()<<endl;
                

            }else if(p.getType()=="fournisseur"){
                //affichage pour fournisseur

            }else if(p.getType()=="employe"){
                //affichage pour employe
                cout<<"Bonjour employé "<<p.getNom()<<' '<<p.getPrenom()<<endl<<endl;
                cout<<"Opération à executer"<<endl;
                cout<<"1 : opération d'inventaire de médicaments"<<endl;
                cout<<"2 : opération monétaire"<<endl;
                cout<<"3 : opération de vente"<<endl;
                cout<<"4 : opération de restock"<<endl;
                cout<<"5 : déconnecter"<<endl;
                cout<<"Votre choix : ";
                cin>>choix;
                switch (choix)
                {
                case 1:{//inventaire de medicament

                    break;
                }
                case 2:{//caisse monnais
                        monnais m;
                        int choix=-1;
                        cout<<"gestion de caisse : "<<endl;
                        cout<<"1 : ajouter un montant"<<endl;
                        cout<<"2 : retirer un montant"<<endl;
                        cout<<"3 : afficher la somme actuelle"<<endl;
                        cout<<"4 : allez au main menu"<<endl;
                        cout<<"Votre choix";
                        cin>>choix;
                        switch (choix)
                        {
                        case 1:{
                            m.ajouterMontant();
                            break;
                        }
                        case 2:{
                            m.retirerMontant();
                            break;
                        }  
                        case 3:{
                            cout<<m;
                            break;
                        }
                        case 4:{
                            break;
                        }
                        default:
                            cout<<"choix non valide";
                            break;
                        }
                    break;
                }
                case 3:{
                    
                    break;
                }
                case 4:{
                    
                    break;
                }
                case 5:{
                    
                    break;
                }
                default:
                    cout<<"choix invalide"<<endl;
                    break;
                }
            }else if(p.getType()=="gerant"){
                //affichage pour gerant

            }else{
                //logged out

            }
        }
        else{
            continue;
        }        
    }
    return 0;
}