#include <iostream> 
#include <fstream> 
#include "abin.h" 
#include "abin_E-S.h" 
#include "Practica2.h"
 
using namespace std; 
 
typedef char tElto; 
const tElto fin = '#';   // Fin de lectura. 

int main(){

   Abin<tElto> A, B, C;
   Abin<op> D; 
 
   ifstream fe("abin.dat");   // Abrir fichero de entrada. 
   rellenarAbin(fe, A);       // Desde fichero. 
   fe.close(); 
   ifstream fs("abin2.dat");   // Abrir fichero de entrada. 
   rellenarAbin(fs, B);       // Desde fichero. 
   fs.close(); 

   ifstream fd("abin3.dat");   // Abrir fichero de entrada. 
   rellenarAbin(fd, D);       // Desde fichero. 
   fd.close();
   
    cout<<"Estos arboles binarios son similares: "<<similaresAbin(A,B)<<endl;
    cout<<"Arbol inicial"<<endl;
    imprimirAbin(A);
    cout<<"Arbol reflejado"<<endl;
    reflejadoAbin(A, C);
    imprimirAbin(C);

    cout<<"El resultado de la operacion es"<<operacionAbin(D);
}