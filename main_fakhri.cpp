#include"iostream"
#include"ostream"
#include"istream"
using namespace std ;
#include"fonction.cpp"
#include"medicament.h"
#include<string>
int main()
{
    medicament med ;
    med.saisirMedicament() ;
    med.afficherMedicament() ;
    return 0 ;
}