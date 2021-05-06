#include<string.h>
#include<vector> 
#include<iostream>
#include"date.h" 
using namespace std ;

class medicament {
    protected :
    int reference ;
    string type ; // forme pharcaceutique ;
    string nomCommercial ; 
    float prixVente ; // prixAchat +10% 
    float prixAchat ; //fournisseur
    int stock ;
    date date_Creation ;
    date date_Fin ;
    public :
    int getReference(){ return reference ;} 
    string getNom() {return nomCommercial ;} 
    float getPrix() { return prixAchat ;} 
    string getType(){ return type ;} 
    void setReference(int r) { reference=r ; } 
    void setPrixAchat(float pa) { prixAchat=pa ;} 
    int getStock(){ return stock; }
    void setNom(string  n ) { nomCommercial=n ;} 
    void setType(string t){ type =t ; } 
    void setStock(int s){ stock=s ; }
    float calcul_prixVente() ;
    medicament(int r=0 ,string t="", string n="" , float pa=0 , int s=0,date d1=date(0,0,0), date d2=date(0,0,0)){
        reference=r ;
        type=t ;
        nomCommercial=n ;
        prixAchat=pa ;
        stock=s ;
        prixVente=calcul_prixVente() ;
        date_Creation=d1 ;
        date_Fin=d2 ;
    }
    void afficherMedicament() ; 
    void saisir() ;
    friend ostream& operator<<(ostream&, medicament& ) ;
    friend istream& operator>>(istream&,medicament& ) ;   // cin et cout  
};

void medicament::saisir()
{
    int j1 ; int j2 ;int m1 ; int m2 ; int a1 ; int a2 ;
    cout<<"\n saisir un medicament"<<endl ;
    cin>>type ;
    cin>>reference ;
    cin>>nomCommercial ;
    cin>>prixAchat ;
    cin>>stock ;
    cout<<"date de creation:"<<endl ;
    cin>>j1 ;
    cin>>m1 ;
    cin>>a1 ;
    date date_Creation(j1,m1,a1) ;
    cout<<"date expiration : "<<endl ;
    cin>>j2 ;
    cin>>m2 ;
    cin>>a2 ;
    date date_Fin(j2,m2,a2) ;
}

float medicament :: calcul_prixVente()
{
    float prixVente ;
    prixVente=prixAchat+((prixAchat*7)/100) ;
    return prixVente ;
}
void medicament :: afficherMedicament()
{
    cout<<"la reference est :"<<reference<<endl ;
    cout<<"le type est :"<<type<<endl ;
    cout<<"le nom commercial :"<<nomCommercial<<endl ;
    cout<<"le stock est :"<<stock<<endl ;
    cout<<"le prix est :"<<prixVente<<endl ;
    cout<<"date de creation :";
    date_Creation.afficher() ;
    cout<<endl<<"date d'expiration";
    date_Fin.afficher() ;

}
ostream& operator<< (ostream& out , medicament& med)
{
    out<<"\n réference :"<<med.reference ;
    out<<"\n Type : "<<med.type ;
    out<<"\n nom Commercial:"<<med.nomCommercial ;
    out<<"\n prix vente: "<<med.prixVente ;
    out<<"\n prix achat: "<<med.prixAchat ;
    out<<"\n stock: "<<med.stock ;
   
    return out ;
}
istream& operator>>(istream& in, medicament& med)
{
    in>>med.reference ;
    in>>med.type ;
    in>>med.nomCommercial ;
    in>>med.prixVente ;
    in>>med.prixAchat ;
    in>>med.stock ;
    return in ; 
}