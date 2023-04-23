#include <iostream>
#include <fstream>

#include "abb.h"
#include "AbbE-S.h"
#include "Practica4.h"

using namespace std;
typedef int tElto;

int main(){

    Abb<tElto> A;
    
    rellenarAbb(A);
    mostrar(A);

    cout<<"Eliminando subarbol...."<<endl;
    A.eliminarSubarbol(9);

    mostrar(A);


    
}