#include"iostream"
#include"ostream"
#include"istream"
using namespace std ;
#include"fonctions.cpp"
#include<fstream>
#include<string>
int main()
{
    fstream f ;
    stockMed::creer_fichier(f) ;
    stockMed::remplir_fichier(f) ;
    f.close() ;
    return 0 ;
}