#include <iostream> 
#include <fstream> 
#include "abin.h" 
#include "abin_E-S.h" 
#include "Practica1.h"
 
using namespace std; 
 
typedef char tElto; 
const tElto fin = '#';   // Fin de lectura. 
 
int main () 
{ 
   Abin<tElto> A, B; 
 
   cout << "\n*** Lectura de árbol binario B de abin.dat ***\n"; 
   ifstream fe("abin.dat");   // Abrir fichero de entrada. 
   rellenarAbin(fe, B);       // Desde fichero. 
   fe.close(); 
   

   int a = contarNodosAbin(B);
   int b = alturaAbin(B);
   int c = profundidadNodoAbin(, A);

   cout<<"El arbol tiene "<<a<<" nodos"<<endl;
   cout<<"El arbol tiene una altura de "<<b<<endl;
}