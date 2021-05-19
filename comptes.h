#include <iostream>
#include <string>
#include <vector>
using namespace std;

class compte{
protected:
    string pseudo;
    string password;
public:
    //==
    bool operator==(const compte&);
    compte(string Pseudo="", string Pass=""){
        this->password=Pass;
        this->pseudo=Pseudo;
    }
    string getPseudo(){return this->pseudo;}
    string getPass(){return this->password;}
    void setPseudo(string Pseudo=""){this->pseudo=Pseudo;}
    void setPass(string Pass=""){this->password=Pass;}


    friend istream& operator>>(istream& in,compte& c){
        cout<<"Votre pseudo : "<<endl;
        cin>>c.pseudo;
        cout<<"Votre mot de passe : "<<endl;
        cin>>c.password;
        return in;
    }
};

bool compte::operator==(const compte& c){
    bool equal=0;
    if((this->getPseudo()==c.pseudo)&&(this->getPass()==c.password)){
        equal=1;
    }
    return equal;
}

class comptes{
private:
    vector<compte> table;
public:
    int find(compte);
    bool ajouter(compte);
    bool verifier(compte);
    bool supprimer(compte);
    
};
int comptes::find(compte c){
    int numCompte=-1;
    if(this->verifier(c)){
        for(int i=0;i<(this->table).size();i++){
            if(c==(this->table)[i]){
                numCompte=i;
            }
        }
    }   
    return numCompte;
}
bool comptes::verifier(compte c){
    for(unsigned int i=0;i<(this->table).size();i++){
        if(c==(this->table)[i]){
            return 1;
        }
        else continue;
    }
    return 0;
}
bool comptes::ajouter(compte c){
    (this->table).push_back(c);
    return 1;
}
bool comptes::supprimer(compte c){
    int position=this->find(c);
    if (position!=-1){
        (this->table).erase((this->table). begin() + position);
    return 1;
    }
    else return 0;
}

class personne{
protected:
    string pseudo;
    string type;
    string nom;
    string prenom;
    string type;
    unsigned int CIN;
    string adresse;
    string mail;
    unsigned int tel;
    
public:
//constructors
    // personne(){
    //     this->pseudo="";
    //     this->type="";
    //     this->nom="";
    //     this->prenom="";
    //     this->CIN=0;
    //     this->adresse="";
    //     this->mail="";
    //     this->tel=0;
    // }
    personne(string Pseudo="",string Type="",string Nom="",string Prenom="",unsigned int Cin=0,string Adresse="",string Mail="",unsigned int Tel=0){
        this->pseudo=Pseudo;
        this->type=Type;
        this->nom=Nom;
        this->prenom=Prenom;
        this->CIN=Cin;
        this->adresse=Adresse;
        this->mail=Mail;
        this->tel=Tel;
    }

//getters
    string getType(){return this->type;}
    string getPseudo(){return this->pseudo;}
    string getNom(){return this->nom;}
    string getPrenom(){return this->prenom;}
    int getCin(){return this->CIN;}
    string getAdresse(){return this->adresse;}
    string getMail(){return this->mail;}
    int getTel(){return this->tel;}
//setters
    void setType(string Type=""){this->type=Type;}
    void setPseudo(string Pseudo=""){this->pseudo=Pseudo;}
    void setNom(string Nom=""){this->nom=Nom;}
    void setPrenom(string Prenom=""){this->prenom=Prenom;}
    void setCin(int Cin=0){this->CIN=Cin;}
    void setAdresse(string Adresse=""){this->adresse=Adresse;}
    void setMail(string Mail=""){this->mail=Mail;}
    void setTel(int Tel=0){this->tel=Tel;}
//methods
    bool identifier(compte);
    void saisir();

};

class personnes{
    vector<personne> table;
public:
    personnes(){
        
    }
    bool existe(compte);
    personne getPersonne(compte);
    void setPersonne(personne p);
    void ajouter(personne p);
    void supprimer(personne p);
    ~personnes(){
        delete[]this;
    }
};
bool personnes::existe(compte c){
    bool test=0;
    for(int i=0;i<(this->table).size();i++){
        if ((this->table)[i].identifier(c)){
            test=1;
            break;
        }
    }
    return test;
}

personne personnes::getPersonne(compte c){
    if (this->existe(c)){
        for(int i=0;i<(this->table).size();i++){
            if ((this->table)[i].identifier(c)){
                return (this->table)[i];
            }
        }
    }
    
}
bool personne::identifier(compte c){
    if (this->getPseudo()==c.getPseudo())
    return 1;
    else return 0;
}

void personne::saisir(){
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

