#ifndef RSA_H
#define RSA_H
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <NTL/ZZ.h>
#include "C:\Repositorios\AlgebraAbstracta-MariaGracielCruzCaceres\MathClass\funciones.h"
#include "C:\Repositorios\AlgebraAbstracta-MariaGracielCruzCaceres\MathClass\numeroAleatorio.h"
using namespace std;
using namespace NTL;

class Rsa
{
    public:
        Rsa(int bits);
        Rsa(ZZ n,ZZ e);
        string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
        string cifrado(string mensaje);
        string descifrado(string mensaje);

        ZZ n, e;
    private:
        ZZ d, fiN, p, q;
        string ZZtoStr(ZZ z);
        ZZ Trc(ZZ M);
};

#endif // RSA_H
