#include <iostream>

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

    if (n == Agen<T>::NODO_NULO)
        return -1;
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
    int maximo, minimo, desequilibrio;

    if (n == Agen<T>::NODO_NULO){
        return 0;

    }else{

        hijo = A.hijoIzqdo(n);
        maximo = 0;
        if(hijo  != Agen<T>::NODO_NULO) minimo = alturaNodoAgen_REC(hijo, A);
        else minimo = 0;
        
        while(hijo != Agen<T>::NODO_NULO){
            minimo = min(minimo, alturaNodoAgen_REC(hijo, A));
            maximo = max(maximo, alturaNodoAgen_REC(hijo, A));
            hijo = A.hermDrcho(hijo);
        }

        desequilibrio = maximo - minimo;
        hijo = A.hijoIzqdo(n);

        while(hijo != Agen<T>::NODO_NULO){
            desequilibrio = max(desequilibrio, desequilibrioAgen_REC(hijo, A));
            hijo = A.hermDrcho(hijo);
        }

        return desequilibrio;
        
    }

}

// EJERCICIO 4 - PODA NODO

template <typename T>
typename Agen<T>::nodo buscar (const char e, Agen<T> A){

    if(A.raiz() == Agen<T>::NODO_NULO) return Agen<T>::NODO_NULO;
    else return buscarREC(e, A.raiz(), A);
}

template <typename T>
typename Agen<T>::nodo buscarREC (const char e,typename Agen<T>::nodo n, Agen<T>& A){

    typename Agen<T>::nodo hijo, bus;


    if(A.elemento(n) == e) return n;
    else{
        typename Agen<T>::nodo aux = buscarREC(e, A.hijoIzqdo(n), A);
            if( aux != Agen<T>::NODO_NULO && A.elemento(aux) == e ) return aux;
            else return buscarREC(e, A.hermDrcho(n), A);
    }
}

template <typename T>
void poda(typename Agen<T>::nodo n, Agen<T> A){
    
    typename Agen<T>::nodo hijo;
    if(n != Agen<T>::NODO_NULO){
    if( A.hijoIzqdo(n) != Agen<T>::NODO_NULO )
        {
            poda(A.hijoIzqdo(n), A);
            A.eliminarHijoIzqdo(n);
        }
        if( A.hermDrcho(n) != Agen<T>::NODO_NULO )
        {
            poda(A.hermDrcho(n), A);
            A.eliminarHermDrcho(n);
        }
}}

