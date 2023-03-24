#include <iostream>
#include "agen.h"
#include "auxiliares.h"

using namespace std;



//EJERCICIO 1 - GRADO DEL ARBOL

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
    
    maximo = alturaAgen(A);
    if (esHoja(n,A)) minimo = profundidadNodo(n, A);
    else minimo = maximo; //Se le asigna este valor para no tenerlo en cuenta, buscamos el nodo hoja con menor longitud 
    
    if (n == Agen<T>::NODO_NULO)
        return 0;
    else{
        
        hijo = A.hijoIzqdo(n);

        while(hijo != Agen<T>::NODO_NULO){
            if(esHoja(hijo, A)) minimo = min(minimo, profundidadNodo(hijo, A));
            else minimo = maximo; //Se le asigna este valor para no tenerlo en cuenta, buscamos el nodo hoja con menor longitud 
            hijo = A.hermDrcho(hijo);
        }

        desequilibrio = maximo - minimo;

        cout<<"Nodo "<<A.elemento(n)<<" Desequilibrio: "<<desequilibrio<<" Maximo: "<<maximo<<" Minimo: "<<minimo<<endl;

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

    while(A.hijoIzqdo(n) != Agen<T>::NODO_NULO){
        A.eliminarHijoIzqdo(n);
    }

    n.
        
}