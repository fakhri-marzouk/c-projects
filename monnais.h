#include <iostream>
using namespace std;

class monnais{
    float montant;
    char currency;
public:
    monnais(float Montant=0,char Currency='$'){
        this->montant=Montant;
        this->currency=Currency;
    }
    float getMontant(){return this->montant;}
    void setMontant(float Montant){this->montant=Montant;}
    void ajouterMontant(){
        float m;
        cout<<"Donnez le montant à ajouter ";
        cin>>m;
        this->montant+=m;
    }
    void retirerMontant(){
        float m;
        cout<<"Donnez le montant à retirer ";
        cin>>m;
        this->montant-=m;
    }
    //cin cout
    friend istream& operator>>(istream& in,monnais& m){
        in>>m.montant;
        in>>m.currency;
        return in;
    }
    friend ostream& operator<<(ostream& out,monnais& m){
        out<<m.montant;
        out<<m.currency;
        return out;
    }
};