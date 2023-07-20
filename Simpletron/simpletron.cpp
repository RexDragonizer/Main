//Programa del Libro Deitel como programar en C++
//Implementacion de clase de Simpletron V 1.0.0

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <iomanip>
using std::showpos;
using std::setfill;
using std::noshowpos;
using std::setw;
using std::internal;

#include "simpletron.h"

//Constructor de simpletron para inicializar una instancia
Simpletron::Simpletron()
{
    memoria = new int[100]; //Crea un objeto arreglo y crea un puntero para el arreglo.
    for ( int i = 0; i < 100; i++)
    {
        memoria[ i ] = 0; // Incia cada posicion del arreglo con 0
    }
    //Inicializando todos las variables
    acumulador = 0;
    contadorInstrucciones = 0;
    codigoDeOperacion = 0;
    operando = 0;
    registroDeInstruccion = 0;
}

void Simpletron::mostrarMensajeInicioLMS()
{
    //Mensaje de Inicio
    cout << "*** Bienvenido a Simpletron! ***"
         << "\n*** Por favor, introduzca en su programa una instruccion ***"
         << "\n*** (o palabra de datos) a la vez . Yo le mostrare el ***"
         << "\n*** numero de ubicacion y un signo de interrogacion (?). ***"
         << "\n*** Entonces usted escribira la palabra para esa ubicacion. ***"
         << "\n*** Escriba el valor centinela -99999 para dejar de ***"
         << "\n*** introducir su programa. ***" << endl;

}

void Simpletron::establecerMemoria( int entrada )
{
    memoria[ entrada ];
}

void Simpletron::entradasLMS()
{
     int entrada = 0;
     bool entraVal;
     int instruccion = 0;

     // Bucle de entredas para guardar las instrucciones en la memoria.
   while ( instruccion < 100 )
    {
        while( ( entrada >= -1 && entrada <= 9999 ) && entrada != -99999 )
        {
             if ( instruccion < 10 )
             {
                 cout << "0";
             }
             cout << instruccion << " ? ";
             cin >> entrada;
             establecerMemoria( instruccion );
             instruccion++;
             if ( instruccion == 100 )
             {
                 cout << "\n***Se completo la carga del programa***\n"; // Mensaje de salida del
                 break;
             }
        }
        instruccion--;
        //Bucle de validacion de entradas
        while ( ( entrada <= -1 || entrada > 9999 ) && entrada != -99999 )
        {
            cout << "\nEntrada incorrecta. Intenta de nuevo con un valor valido. " << endl;
            if ( instruccion < 10 )
             {
                 cout << "0";
             }
            cout << instruccion << " ? ";
            cin >> entrada;
            establecerMemoria( instruccion );
        }
        instruccion++;
        // Condicion de valor centinela
        if ( entrada == -99999)
            {
                cout << "\n***Se completo la carga del programa***\n"; // Mesaje de salida del programa
                break;

            }
    }
}

void Simpletron::ejecutar()
{
    cout << "***Empieza la ejecucion del programa***\n"; //mensaje de inicio de ejecucion
    //bucle para ejecucion del programa
    while ( contadorInstrucciones < 100 )
    {
        registroDeInstruccion = memoria[ contadorInstrucciones ];
        LMS();
    }
}

void Simpletron::LMS()
{
    //int palabra;

    //Divide la instruccion
    codigoDeOperacion = registroDeInstruccion / 100;
    operando = registroDeInstruccion % 100;
    ++contadorInstrucciones;

    switch ( codigoDeOperacion )
    {
    case LEE:
        cin >> memoria[ operando ];
        break;
    case ESCRIBE:
        cout << memoria[ operando ];
        break;
    case CARGA:
        acumulador = memoria[ operando ];
        break;
    case ALMACENA:
        memoria[ operando ] = acumulador;
        break;
    case SUMA:
        acumulador += memoria[ operando ];
        break;
    case RESTA:
        acumulador -= memoria[ operando ];
        break;
    case DIVIDE:
        acumulador /= memoria[ operando ];
        break;
    case MULTIPLICA:
        acumulador *= memoria[ operando ];
        break;
    case BIFURCA:
        contadorInstrucciones = operando;
        break;
    case BIFURCANEG:
        if ( acumulador < 0 )
            contadorInstrucciones = operando;
        break;
    case BIFURCACERO:
        if ( acumulador == 0 )
            contadorInstrucciones = operando;
        break;
    //Alto imprime el mensaje
    case ALTO:
        cout << "*** Termino la ejecucion de Simpletron ***" << endl;
        mostrarMemoria();
        contadorInstrucciones = 100;
        break;
    }
}
void Simpletron::mostrarMemoria()
{
    cout << "REGISTROS:" << endl;
	cout << "accumulador:             " << showpos << setw( 5 ) << setfill( '0' ) << internal << acumulador << endl;
	cout << "contador        :        " << showpos << setw( 2 ) << setfill( '0' ) << internal << contadorInstrucciones << endl;
	cout << "registroDeInstruccion:   " << showpos << setw( 5 ) << setfill( '0' ) << internal << registroDeInstruccion << endl;
	cout << "codigoDeOperacion:       " << showpos << setw( 2 ) << setfill( '0' ) << internal << codigoDeOperacion << endl;
	cout << "operando:                " << showpos << setw( 2 ) << setfill( '0' ) << internal << operando << endl;
	cout << "" << endl;
	cout << "MEMORIA:" << endl;
	cout << "   0     1     2     3     4     5     6     7     8     9 " << endl;
	// Print out the memory block.
	cout << "00 ";
	for ( int i=0; i<10 ; i++ )
    {
		cout << showpos << setw( 5 ) << setfill( '0' ) << internal  << memoria[ i ] << " ";
	}
	cout << endl;
	for ( int s=10; s<100; s=s+10 )
    {
		    cout << noshowpos << s << " ";
		    for ( int i=0; i<10; i++ )
		    {
			    cout << showpos << setw( 5 ) << setfill( '0' ) << internal  << memoria[ s+i ] << " ";
		    }
            cout << endl;
    }
}

void Simpletron::mostrarError( string codigoError )
{
  // Mensaje de error si obtiene valores mayores a 9999 y menores a -9999
  if ( codigoError.compare( "faltal" ) == 0 )
  {
      cout << "\n*** La ejecucion de Simpletron se termino en forma anormal ***" << endl;
      contadorInstrucciones = 100;
      mostrarMemoria();
  }
  // Mensaje de error si intenta dividir entre 0
    if ( codigoError.compare( "divCero" ) == 0 )
  {
      cout << "\n*** Intento dividir entre 0 ***" << endl;
      contadorInstrucciones = 100;
      mostrarMemoria();
  }
}














