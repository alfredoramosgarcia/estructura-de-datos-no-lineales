#ifndef ABB_AYUDA_HPP
#define ABB_AYUDA_HPP

#include <iostream>
#include <fstream>

#include "abb.h"

using namespace std;

template <typename T>
void mostrar(const Abb<T>& A){
    if(!A.vacio()){
        cout<<A.elemento()<<" "<<endl;
        cout<<"Hijo izquierdo del elemento "<<A.elemento()<<": "; mostrar(A.izqdo()); cout<<endl;
        cout<<"Hijo derecho del elemento "<<A.elemento()<<": "; mostrar(A.drcho()); cout<<endl;
    }
}

template <typename T>
void insertar(istream& f, Abb<T>& A){
    T ins;
    while (f >> ins){
        A.insertar(ins);
    }
}

template <typename T>
void imprimir (ostream& f, const Abb<T>& A){
    if(!A.vacio()){
        f << A.elemento() << " ";
        imprimir(f,A.izqdo());
        imprimir(f,A.drcho());
    }
}

template <typename T>
void rellenarAbb(Abb<T>& A){

    int a;

    cout<<"Introduzca un elemento en el Abb: ";
    cin>>a;

    while(a>0){
        A.insertar(a);

        cout<<"Introduzca un elemento en el Abb: ";
        cin>>a;
    }
}

#endif //ABB_AYUDA_HPP