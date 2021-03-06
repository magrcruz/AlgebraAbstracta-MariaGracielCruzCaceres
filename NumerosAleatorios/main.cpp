#include <iostream>
#include <vector>
#include <windows.h>
#include <psapi.h>
#include <bitset>
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;

vector<int> fillWithMemoryInfo() {
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    string a;
    if (EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {//obtiene los procesos en aProcesses
        cProcesses = cbNeeded / sizeof(DWORD);// Calcula cuantos procesos fueron retornados
        for (int i = 100; i < cProcesses&& a.size()<15; i++){
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, aProcesses[i]);
            if (NULL != hProcess){
                PROCESS_MEMORY_COUNTERS pmc;
                if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
                    a=to_string(pmc.PageFaultCount)+to_string(pmc.WorkingSetSize)+
                    to_string(pmc.QuotaPagedPoolUsage)+to_string(pmc.QuotaNonPagedPoolUsage)+to_string(pmc.PeakPagefileUsage);
                } // a = parametros del Proceso
            }
            CloseHandle(hProcess);
        }
    }
    vector<int> k;
    for(int i=0, j=0;i<5;i++,j+=3){
        int n=stoi(a.substr(j,3));
        while(n>255) n>>=1;
        while(n<128) n<<=1;
        k.push_back(n);
    }
    return k;
}
int modint(int a,int n){
    int q=a/n;
    if(q<0) q--;
    return a-(n*q);
}
vector<bool> initialize(vector<int> semilla){
    vector<int> S;//inicializo con el tamano ya que no necesita reubicar el vector en caso sea mayor
    for(int i=0;i<256;i++) S.push_back(i);
    vector<int> K;
    for(int i=0,k=0;i<=51;i++)
        for(int j=0;j<5;j++,k++)
            K.push_back(semilla[j]);
    for(int i=0,f=0;i<256;i++){
        f=modint(f+S[i]+K[i],256);
        swap(S[i],S[f]);
    }
    vector<int> Or;
    for(int i=0,f=0,k=0;k<8;k++){
        i=modint(i+1,256);
        f=modint(f+S.at(i),256);
        swap(S.at(i),S.at(f));
        Or.push_back(S.at(modint(S.at(i)+S.at(f),256)));//t
    }
    vector<bool> out;
    for(int i=0;i<8;i++){
        bitset<8> aux(Or[i]);
        for(int j=0;j<8;j++)
            out.push_back(aux[j]);
    }
    return out;
}

void izqRotate(vector<bool> &vec, int times){
    vec.insert(vec.end(),vec.begin(),vec.begin()+times);
    vec.erase(vec.begin(),vec.begin()+times);
}

void print(vector<bool>::iterator begins,vector<bool>::iterator ends){
    while(begins!=ends) cout<<*begins++<<" ";
    cout<<endl;
}

vector<bool> DES(int bits=1024){
    vector<bool>k=initialize(fillWithMemoryInfo());
    int nBits=bits/48+1;
    int PC_1[]={56,48,40,32,24,16,8,0,57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,60,52,44,36,28,20,12,4,27,19,11,3};
    int PC_2[]={13,16,10,23,0,4,2,27,14,5,20,9,22,18,11,3,25,7,15,6,26,19,12,1,40,51,30,36,46,54,29,39,50,44,32,47,43,48,38,55,33,52,45,41,49,35,28,31};
    int rotaciones[]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1,1,1,2,2,2,2};
    vector<bool> K;//para guardar todas las k
    vector<bool> c; vector<bool> d;
    for(int i=0;i<28;i++) c.push_back(k.at(PC_1[i]));
    for(int i=28;i<56;i++) d.push_back(k.at(PC_1[i]));
    for(int i=0;i<nBits;i++){
        izqRotate(c,rotaciones[i]);
        izqRotate(d,rotaciones[i]);
        vector<bool> both(c.begin(),c.end());
        both.insert(both.end(),d.begin(),d.end());
        for(int i=0;i<48;i++) K.push_back(both.at(PC_2[i]));
    }
    K.resize(bits);
    K[0]=1; K[bits-1]=1;
    cout<<endl;
    return K;
}

ZZ conversion(vector<bool> vec){
    ZZ salida(0);
    ZZ i(1);
    for(vector<bool>::reverse_iterator it=vec.rbegin();it!=vec.rend();++it){
        if(*it) salida+=i;
        i<<=1;
    }
    return salida;
}

int main(){
    conversion(DES(1024));
    return 0;
}
