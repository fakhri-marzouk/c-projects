#include<iostream>
using namespace std ;
#include"medicament.h" 
#include<string>
#include<vector>
void givemename(string nom)
{
    char ch[101];
    stockMed sm ;
    ifstream fin;
    fin.open("stockmedicament.txt");
    fin.getline(ch,100,'\n');
    bool existe=0;
    while(!fin.eof())
    {
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,':');
        fin.getline(ch,100,'\n');
        string b(ch);
        if (b==nom)
        {
            cout<<"medicament trouvé"<<endl;//goto et1 ;
            existe=1;
            break;
        } 
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');
        fin.getline(ch,100,'\n');   
    }
    if (existe==0){
    cout<<"medicament n'existe pas "<<endl ;
    }
}
int main()
{
    stockMed a;
    givemename("v");
    return 0;
}
