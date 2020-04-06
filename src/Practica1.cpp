#include "Practica1.h"

Practica1::Practica1()
{
    //ctor
}

Practica1::~Practica1()
{
    //dtor
}
void Practica1::printArr(char* start,char*ends){
    while(start!=ends){
        cout<<*start<<" ";
        start++;
    }
    cout<<endl;
}

string Practica1::charToStr(char arr[],int tam){
    string str;
    for (int i=0;i<tam;i++)
        str+=*(arr+i);
    return str;
}

string Practica1::mayToMin(string &in){
    for (int i=0;i<in.length();i++){
        if (in[i]>=97&&in[i]<=122) in[i]-=32;
        else if (in[i]>=65&&in[i]<=90) in[i]+=32;
    }
    return in;
}

int Practica1::contarInStr(string frase,string palabra){
    int counting=0;
    size_t finder=frase.find(palabra);
    while (finder!=string::npos){
        counting++;
        finder=frase.find(palabra,finder+1);
    }
    return counting;
}

void Practica1::printEnLineas(string cadena){
    string::const_iterator i=cadena.begin();
    while(i!=cadena.end())
        cout<<*i++<<endl;
}

void Practica1::buscarYremplazar(string &primero,string segundo,string tercero){
    size_t finder=primero.find(segundo);
    while (finder!=string::npos){
        primero.replace(finder,segundo.size(),tercero);
        finder=primero.find(segundo,finder+1);
    }
}

void Practica1::writeNnumeros(int n){
    ofstream salida("numeros.txt");
    for (int i=0;i<n;i++)
        salida << (rand()%999)+1 << endl;
    salida.close();
}

int Practica1::sumatoriaArchivo(){
    ifstream archivo("numeros.txt");
    int suma=0;
    string linea;
    while (getline(archivo,linea))
        suma+=stoi(linea);
    return suma;
}

string Practica1::cifrado(string str,bool cifrar,int root){
    string out=str;
    int diference=0;
    if(!cifrar) root*=-1;
    for(int i=0;i<out.size();i++){
        if (out[i]>=97&&out[i]<=122) diference=97;
        else if(out[i]>=65&&out[i]<=90) diference=65;
        if(diference){
            out[i]=out[i]-diference+root;
            int mod=out[i]%26;
            if(mod<0) mod+=26;
            out[i]=(mod)+diference;
        }
        diference=0;
    }
    return out;
}

void Practica1::juegoAhorcado(){
    while(true){
        int intentRestantes=7;
        cout<<"AHORCADO"<<endl;
        string intento;
        string respuesta=obtenerPalabra();
        string jugando(respuesta.size(),'X');
        size_t index;
        while (intentRestantes){
            cout<<"Adivine la palabra: "<<jugando<<endl;
            cin>>intento;
            index=respuesta.find(intento[0]);//busca si hay al menos una letra como la que ingreso
            if(index==string::npos){
                cout<<"no"<<endl;
                drawMan(intentRestantes);
            }
            else{
                cout<<"si"<<endl;
                revelarInStr(jugando,respuesta,intento);
            }
        }
    cout<<"Felicidades!!! Adivino mi palabra. Desea jugar otra vez? si/no"<<endl;
    cin>>respuesta;
    if (respuesta=="no") return;
    }
}


string Practica1::obtenerPalabra(){//incompleto
/*    cout<<"De donde quieres elegir la palabra:"<<endl;
    cout<<"1. Ingresar palabra"<<endl;
    cout<<"2. Elegir aleatoriamente del programa"<<endl;
    cout<<"3. Elegir aleatoriamente de archivo"<<endl;
    switch(cin.get()){

    }
*/
    return "Imooto";
}

void Practica1::revelarInStr(string &base,string rpta,string key){
    size_t finder=rpta.find(key);
    while (finder!=string::npos){
        base.replace(finder,1,key);
        finder=rpta.find(key,finder+1);
    }
}

void Practica1::drawMan(int intentos){
    string man[]={" 0\n","/","|","\ \n"," |\n","/"," \ "};
    for(int i=0;i<intentos;i++)
        cout<<man[i];
}








