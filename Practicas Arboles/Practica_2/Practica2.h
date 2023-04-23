#include "abin.h"

//EJERCICIO 1

template <typename T>
bool similaresAbin(Abin<T> A, Abin<T> B){

    return similaresAbin_REC(A.raiz(), A, B.raiz(), B);
}

template <typename T>
bool similaresAbin_REC(typename Abin<T>::nodo nA, Abin<T> A,typename Abin<T>::nodo nB, Abin<T> B){
    if(nA==Abin<T>::NODO_NULO && nB==Abin<T>::NODO_NULO) return true;
    else{
        if((nA == Abin<T>::NODO_NULO && nB != Abin<T>::NODO_NULO) || (nA != Abin<T>::NODO_NULO && nB == Abin<T>::NODO_NULO))
            return false;
        else
            return similaresAbin_REC(A.hijoIzqdo(nA), A, B.hijoIzqdo(nB), B) && similaresAbin_REC(A.hijoDrcho(nA), A, B.hijoDrcho(nB), B);}
}

//EJERCICIO 2

template <typename T>
void reflejadoAbin(Abin<T> A, Abin<T>& B){
    B.insertarRaiz(A.elemento(A.raiz()));

    return reflejadoAbin_REC(A.raiz(), A, B.raiz(), B);
}

template <typename T>
void reflejadoAbin_REC(typename Abin<T>::nodo nA, Abin<T> A,typename Abin<T>::nodo nB, Abin<T> B){

    
    if(A.hijoIzqdo(nA) != Abin<T>::NODO_NULO){
         B.insertarHijoDrcho(nB, A.elemento(A.hijoIzqdo(nA)));
        reflejadoAbin_REC(A.hijoIzqdo(nA), A, B.hijoDrcho(nB), B);
    }
    
    
    if(A.hijoDrcho(nA) != Abin<T>::NODO_NULO){
        B.insertarHijoIzqdo(nB, A.elemento(A.hijoDrcho(nA)));
        reflejadoAbin_REC(A.hijoDrcho(nA), A, B.hijoIzqdo(nB), B);
    }


}

//EJERCICIO 3

union op{
    char operador;
    double operando;
};


double operacionAbin(Abin<op> A){
    return operacionAbin_REC(A.raiz(), A);
}

double operacionAbin_REC(typename Abin<op>::nodo n, Abin<op> A){

    if(A.hijoIzqdo(n) == Abin<op>::NODO_NULO)
        return n->elto.operando;
    else{
        switch(n->elto.operador){
            case '+': return operacionAbin_REC(A.hijoIzqdo(n), A) + operacionAbin_REC(A.hijoDrcho(n), A); break;
            case '-': return operacionAbin_REC(A.hijoIzqdo(n), A) - operacionAbin_REC(A.hijoDrcho(n), A); break;
            case '*': return operacionAbin_REC(A.hijoIzqdo(n), A) * operacionAbin_REC(A.hijoDrcho(n), A); break;
            case '/': return operacionAbin_REC(A.hijoIzqdo(n), A) / operacionAbin_REC(A.hijoDrcho(n), A); break;
            default: cout<<"Operacion no considerada"<<endl;
        }
    }
}

