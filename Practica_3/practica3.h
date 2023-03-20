#include <iostream>

using namespace std;
//FUNCIONES AUXILIARES

int max(int a, int b){
    if (a>b)
        return a;
    else
        return b;
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

    return alturaAgen_REC(A.raiz(), A);
}

template <typename T>
int alturaAgen_REC(typename Agen<T>::nodo n, Agen<T> A){

    typename Agen<T>::nodo hijo;
    int maximo;
    if (esHoja(n, A))
        return 0;
    else{
        maximo = 0;
        hijo = A.hijoIzqdo(n);

        while(hijo != Agen<T>::NODO_NULO){
            maximo = 1 + max(maximo, alturaAgen_REC(A.hijoIzqdo(hijo), A));
            hijo = A.hermDrcho(hijo);
        }

        return maximo;

    }
}

//EJERCICIO 1 - GRADO DEL ARBOL

#include "agen.h"

template <typename T>
int gradoAgen (Agen<T> A){

    return gradoAgen_REC(A.raiz(), A);
}

template <typename T>
int gradoAgen_REC(typename Agen<T>::nodo n, Agen<T> A){

    int maximo;
    typename Agen<T>::nodo hijo;

    if (n == Agen<T>::NODO_NULO)
        return 0;
    else{
        maximo = numHijos(n, A);
        hijo = A.hijoIzqdo(n);

        while(hijo != Agen<T>::NODO_NULO){
            maximo = max(maximo, gradoAgen_REC(hijo, A));
            hijo = A.hermDrcho(hijo);
        }

        return maximo;
    }
}

//EJERCICIO 2 - PROFUNDIDAD DE UN NODO

template <typename T>
int profundidadNodo (typename Agen<T>::nodo n, Agen<T> A){

    if (n == A.raiz())
        return 0;
    else
        return 1 + profundidadNodo(A.padre(n), A);
}

//EJERCICIO 3 - DESEQUILIBRIO POR NIVELES

template <typename T>
int desequilibrioAgen(Agen<T> A){

    return desequilibrioAgen_REC(A.raiz(), A);
}

template <typename T>
int desequilibrioAgen_REC(typename Agen<T>::nodo n, Agen<T> A){

    typename Agen<T>::nodo hijo;

    if (esHoja(n, A))
        return alturaAgen(A) - profundidadNodo(n,A);
    else{
        hijo = A.hijoIzqdo(n);

        while(hijo != Agen<T>::NODO_NULO){
            desequilibrioAgen_REC(hijo, A);
            hijo = A.hermDrcho(hijo);
        }
    }

    return 0;
}

