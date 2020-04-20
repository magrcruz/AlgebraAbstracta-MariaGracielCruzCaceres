#include <iostream>
#include <string>
#include <fstream>
#include "VigenereClass.h"
#include "practica2.h"

using namespace std;


int main(){
//insertar texto cifrado manualmente 3a
    bool porConsola;
    string mensaje,aux,cifrado;
    VigenereClass a;

    ifstream archivo("texto.txt");
    if(archivo.fail())
        cout<<"Fallaste"<<endl;
    else{
        while(getline(archivo,aux)){
            mensaje+=aux;
            mensaje+='\n';
        }
    }
    cifrado=a.cifrado(mensaje);
    cout<<cifrado<<endl;
    cout<<a.descifrado(cifrado)<<endl;

    cout<<practica2::insertAQUI10W4(mensaje);
}