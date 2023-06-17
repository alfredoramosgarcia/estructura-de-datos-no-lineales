#include <iostream>
#include <fstream>
#include "agen.h"
#include "agen_E-S.h"
#include "practica3.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura
template <typename T> bool similaresAgen(const Agen<T> &A, const Agen<T> &B);
template <typename T> bool similaresAgen_REC(typename Agen<T>::nodo na, const Agen<T> &A,typename Agen<T>::nodo nb, const Agen<T> &B);
//template <typename T> bool esHoja(typename Agen<T>::nodo n, const Agen<T> A);
int main ()
{
Agen<tElto> A, B;
//cout << "*** Lectura del árbol A ***\n";
/*rellenarAgen(A, fin); // Desde std::cin
ofstream fs("agen.dat"); // Abrir fichero de salida.
imprimirAgen(fs, A, fin); // En fichero.
fs.close();
cout << "\n*** Árbol A guardado en fichero agen.dat ***\n";*/
//cout << "\n*** Lectura de árbol B de agen.dat ***\n";
/*ifstream fe("agen.dat"); // Abrir fichero de entrada.
rellenarAgen(fe, A); // Desde fichero.
fe.close();

*/ifstream f("agen2.dat"); // Abrir fichero de entrada.
rellenarAgen(f, B); // Desde fichero.
f.close();

    cout<<similaresAgen(A,B);
    //cout<<gradoAgen(A)<<" "<<gradoAgen(B);



}


template <typename T> 
bool similaresAgen(const Agen<T> &A, const Agen<T> &B){

    return similaresAgen_REC(A.raiz(), A, B.raiz(), B);
}


template <typename T> 
bool similaresAgen_REC(typename Agen<T>::nodo na, const Agen<T> &A,typename Agen<T>::nodo nb, const Agen<T> &B){

    bool similar = true;

    if (na == Agen<T>::NODO_NULO){
        if (nb == Agen<T>::NODO_NULO){
            return true;
        }
    }

    if (nb == Agen<T>::NODO_NULO){
        if (na == Agen<T>::NODO_NULO){
            return true;
        }
    }
    if (esHoja(na, A) && esHoja(nb,B)){
        if(A.elemento(na) != B.elemento(nb)) return false;
    }else{
        typename Agen<T>::nodo hijoA = A.hijoIzqdo(na);
        typename Agen<T>::nodo hijoB = B.hijoIzqdo(nb);

        if(hijoA != Agen<T>::NODO_NULO && hijoB != Agen<T>::NODO_NULO){
            while(hijoA != Agen<T>::NODO_NULO && hijoB != Agen<T>::NODO_NULO){
                similar = similaresAgen_REC(hijoA, A, hijoB, B);
                if (!similar) return false;
                hijoA = A.hermDrcho(hijoA);
                hijoB = B.hermDrcho(hijoB);
            }

            if(hijoA != Agen<T>::NODO_NULO || hijoB != Agen<T>::NODO_NULO) return false;
        }else return false;
    }

    return similar;

}
/*template <typename T> 
bool esHoja(typename Agen<T>::nodo n, const Agen<T> A){

    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO) return true;
    else return false;

}*/