#include <iostream>
#include <fstream>
#include "agen.h"
#include "agen_E-S.h"
#include "practica3.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura
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
ifstream fe("agen.dat"); // Abrir fichero de entrada.
rellenarAgen(fe, B); // Desde fichero.
fe.close();
//cout << "\n*** Mostrar árbol B ***\n";
//imprimirAgen(B); // En std::cout

    cout<<"El grado del arbol es "<<gradoAgen(B)<<endl;
    cout<<"El desequilibrio del arbol es "<<desequilibrioAgen(B)<<endl;

    typename Agen<tElto>::nodo n = Agen<tElto>::NODO_NULO;
    n = buscar('o', A);
    if (n != Agen<tElto>::NODO_NULO) cout<<"NO ES NODO NULO";
    else cout<<" ES NODO NULO";
    poda(n, A);

}