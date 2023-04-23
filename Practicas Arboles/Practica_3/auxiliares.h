#include <iostream>
#include "agen.h"

using namespace std;

//FUNCIONES AUXILIARES


int max(int a, int b){
    if (a>b)
        return a;
    else
        return b;
}

int min(int a, int b){
    if (a>b)
        return b;
    else
        return a;
}

template <typename T>
int numHijos(typename Agen<T>::nodo n, Agen<T> A){

    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    int cont = 0;
    while (hijo != Agen<T>::NODO_NULO){
        cont++;
        hijo = A.hermDrcho(hijo);
    }

    return cont;    
}

template <typename T>
int esHoja(typename Agen<T>::nodo n, Agen<T> A){

    if (A.hijoIzqdo(n) == Agen<T>::NODO_NULO)
        return true;
    else
        return false;
}

template <typename T>
int alturaAgen(Agen<T> A){

        return alturaNodoAgen_REC(A.raiz(), A);
}


template <typename T>
int alturaNodoAgen_REC(typename Agen<T>::nodo n, Agen<T> A){

    typename Agen<T>::nodo hijo;
    int maximo;
    if (esHoja(n, A))
        return 0;
    else{
        maximo = 0;
        hijo = A.hijoIzqdo(n);

        while(hijo != Agen<T>::NODO_NULO){
            maximo = max(maximo, 1 + alturaNodoAgen_REC(hijo, A));
            hijo = A.hermDrcho(hijo);
        }

        return maximo;

    }
}