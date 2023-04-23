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
    //cout<<"El desequilibrio del arbol es ";
    cout<<desequilibrioAgen(B)<<" -> Este es el desequilibrio del arbol general"<<endl;

    
    cout<<"Arbol antes de la poda"<<endl;
    imprimirAgen(B); cout<<endl;

    poda(B, 'o');

    cout<<"Arbol despues de la poda"<<endl;
    imprimirAgen(B); cout<<endl;

}