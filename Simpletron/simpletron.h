//Programa del Libro Deitel como programar en C++
//Version 1.0.0
#include <iostream>
using std::cout;

#include <string>
using std::string;

//Operaciones de entrada/salida
const int LEE = 10; // Lee una palabra desde el teclado y la introduce en una ubicacion especifica de la memoria.
const int ESCRIBE = 11; // Escribe una palabra de una ubicacion especica de la memoria y la imprime en la pantalla.
const int CARGA = 20; // Carga una palabra de una ubicacion especifica de la memoria y la coloca y la coloca en el acumulador.
const int ALMACENA = 21; // Almacena una palabra del acumulador dentro de una ubicacion especifica de la memoria.
//Operaciones Aritmeticas
const int SUMA = 30; // Suma una palabra de una ubicacion especifica de memoria a la palabra en el acumulador (Actualiza el acumulador)
const int RESTA = 31; // Resta una palabra de una ubicacion especifica de memoria a la palabra en el acumulador (Actualiza el resultado en el acumulador)
const int DIVIDE = 32; // Divide una palabra de una ubicacion especifica de memoria por la palabra en el acumulador (Actualiza el resultado en el acumulador)
const int MULTIPLICA = 33; //Multiplica una palabra de una ubicacion especifica de memoria por la palabra en el acumulador (Actualiza el resultado en el acumulador)
//Operaciones de transferencia de control
const int BIFURCA = 40; //Bifurca hacia una ubicacion especifica de memoria.
const int BIFURCANEG = 41; //Bifurca hacia una ubicacion especifica de memoria si el acumulador es negativo.
const int BIFURCACERO = 42; // Bifurca hacia una ubicacion especifica de memoria si el acumulador es cero.
const int ALTO = 43; //Alto. El programa completo su tarea.

//Clase de simpletron
class Simpletron
{
//Declaracion de funciones publicas
public:
    Simpletron();
    void mostrarMensajeInicioLMS();
    void entradasLMS();
    void ejecutar();
    void LMS();
// Decclaracion de funciones y variables privadas
private:
    int *memoria;
    void establecerMemoria( int );
    void mostrarMemoria();
    int acumulador;
    int contadorInstrucciones;
    int codigoOperacionLMS;
    int operador;
    int registroIntrucciones;
    int error( string );

};
