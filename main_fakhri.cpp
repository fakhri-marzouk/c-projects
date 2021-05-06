#include<iostream>
using namespace std ;
#include"fonction.cpp"
#include"medicament.h"
int main()
{
    medicament med ;
    med.saisir() ;
    med.afficherMedicament() ;
    return 0 ;
}