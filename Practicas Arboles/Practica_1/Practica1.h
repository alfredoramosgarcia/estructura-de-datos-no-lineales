#include "abin.h"
#include "math.h"

int max(int a, int b){
    if(a<b)
        return b;
    else
        return a;
}

//EJERCICIO 1
template <typename T>
int contarNodosAbin(const Abin<T> &A){
    return contarNodosAbin_Rec(A.raiz(), A);
}

template <typename T>
int contarNodosAbin_Rec(typename Abin<T>::nodo n, const Abin<T> &A) {
    if (n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + contarNodosAbin_Rec(A.hijoIzqdo(n), A) + contarNodosAbin_Rec(A.hijoDrcho(n), A);
}

//EJERCICIO 2

template <typename T>
int alturaAbin (const Abin<T> &A){

    return alturaAbin_Rec(A.raiz(), A);
}

template <typename T>
int alturaAbin_Rec(typename Abin<T>::nodo n, const Abin<T> &A) {
    if (n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + max(alturaAbin_Rec(A.hijoIzqdo(n), A), alturaAbin_Rec(A.hijoDrcho(n), A));
}

//EJERCICIO 3

template <typename T>
int profundidadNodoAbin(typename Abin<T>::nodo n, const Abin<T> &A){

    if (n == A.raiz())
        return 0;
    else
        return 1 + profundidadNodoAbin(A.padre(n), A);
}  

//EJERCICIO 6

template <typename T>
int desequilibrioAbin(Abin<T> A){

    return desequilibrioAbin_REC(A.raiz(), A);
}

template <typename T>
int desequilibrioAbin_REC(typename Abin<T>::nodo n, Abin<T> A){


    int desequilibrioI, desequilibrioD;

    if (n == Abin<T>::NODO_NULO)
        return 0;
    else{
        desequilibrioI = alturaAbin_Rec(A.hijoIzqdo(n), A);
        desequilibrioD = alturaAbin_Rec(A.hijoDrcho(n), A);

        return std::abs(desequilibrioI - desequilibrioD);

        
    }
}

//EJERCICIO 7

template <typename T>
bool pseudocompletoAbin(Abin<T> A){
    return pseudocompletoAbin_REC(A.raiz(), A, 0, alturaAbin(A) - 1);
}

template <typename T>
bool pseudocompletoAbin_REC(typename Abin<T>::nodo n, Abin<T> A, int nivelActual, int penultimoNivel){

    if( n != Abin<T>::NODO_NULO )
		if (nivelActual == penultimoNivel)
			if (A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO)
				return true;
			else if (A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO)
				return true;
			else
				return false;
		else
			return pseudocompletoAbin_REC(A.hijoIzqdo(n), A, nivelActual + 1, penultimoNivel) && pseudocompletoAbin_REC(A.hijoDrcho(n), A, nivelActual + 1, penultimoNivel);
	else 
		return true;
}