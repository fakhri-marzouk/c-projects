#include <iostream>
#include <string>
#include <vector>

using namespace std;

class compte{
protected:
    string pseudo;
    string pass;
public:
    compte(string Pseudo="", string Pass=""){
        this->pass=Pass;
        this->pseudo=Pseudo;
    }
    ~compte(){
        delete this;
    }
    string getPseudo(){return this->pseudo;}
    string getPass(){return this->pass;}
    void setPseudo(string Pseudo=""){this->pseudo=Pseudo;}
    void setPass(string Pass=""){this->pass=Pass;}

};
class personne{
protected:
    string pseudo;
    string nom;
    string prenom;
    int CIN;
    string adresse;
    string mail;
    int tel;
public:
    string getPseudo(){return this->pseudo;}
    string getNom(){return this->nom;}
    string getPrenom(){return this->prenom;}
    int getCin(){return this->CIN;}
    string getAdresse(){return this->adresse;}
    string getMail(){return this->mail;}
    int getTel(){return this->tel;}
    void setPseudo(string Pseudo=""){this->pseudo=Pseudo;}
    void setNom(string Nom=""){this->nom=Nom;}
    void setPrenom(string Prenom=""){this->prenom=Prenom;}
    void setCin(int Cin=0){this->CIN=Cin;}
    void setAdresse(string Adresse=""){this->adresse=Adresse;}
    void setMail(string Mail=""){this->mail=Mail;}
    void setTel(int Tel=0){this->tel=Tel;}
    void identifier(compte);
    void saisir();

};
class employe: public personne{
    
};
class fournisseur: public personne{

};
class client: public personne{

};
class gerant: public personne{

};

class tableComptes{
    vector<personne> t;
public:
    tableComptes(){
        
    }
    personne getPersonne();
    void setPersonne(personne p);
    void ajouter(personne p);
    void supprimer(personne p);
    ~tableComptes(){
        delete[]this;
    }
};



void personne::identifier(compte c){
    this->pseudo=c.getPseudo();
}

void personne::saisir(){
    cout<<"pseudo: ";
    cin>>this->pseudo;
    cout<<endl<<"nom: ";
    cin>>this->nom;
    cout<<endl<<"prénom: ";
    cin>>this->prenom;
    cout<<endl<<"CIN: ";
    cin >> this->CIN;
    cout<<endl<<"adresse: ";
    cin >> this->adresse;
    cout<<endl<<"Mail: ";
    cin >> this->mail;
    cout<<endl<<"Tel: ";
    cin >> this->tel;
}