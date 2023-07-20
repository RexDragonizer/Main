//Programa del Libro Deitel como programar en C++
//Implementacion de clase de Simpletron V 1.0.0

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include "simpletron.h"

int main()
{
    //Crea un objeto simpletron
    Simpletron miSimpletron;

    miSimpletron.mostrarMensajeInicioLMS();
    miSimpletron.entradasLMS();
    miSimpletron.ejecutar();
    return 0;

}
