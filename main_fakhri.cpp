#include<iostream>
using namespace std ;
#include"fonction.cpp"
#include"medicament.h"
int main()
{
    medicament med(1,"ff","oo",55,0) ;
    med.afficher() ;
    return 0 ;
}