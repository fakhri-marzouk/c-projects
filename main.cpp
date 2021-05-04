#include"comptes.h"

int main(){
    comptes tabComptes;
    personnes tabPersonnes;
    personne p;
    compte c;
    while(1){
        bool loggedIn=0;
        cout<<"voulez-vous s'authentifier ou créer un compte?"<<endl;
        cout<<"1 : s'authentifier"<<endl;
        cout<<"2 : créer un compte"<<endl;
        cout<<"Votre choix : ";
        int choix;
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
                    cout<<"choix non existant"<<endl;
                    break;
                }
            }//fin switch pour choisir type
            //creation d'une personne
            cout<<"création d'un compte"<<endl;
            string Pseudo="";
            string Password="";
            do{
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
        if(loggedIn){
            if (p.getType()=="client"){
                //affichage pour client

            }else if(p.getType()=="fournisseur"){
                //affichage pour fournisseur

            }else if(p.getType()=="employe"){
                //affichage pour employe

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