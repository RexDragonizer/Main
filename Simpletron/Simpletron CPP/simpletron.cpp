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

void Simpletron();
void mostrarMensajeInicioLMS();
void entradasLMS();
void ejecutar();
void LMS();
int *memoria;
void establecerMemoria( int, int );
void mostrarMemoria();
int acumulador;
int contadorInstrucciones;
int codigoDeOperacion;
int operando;
int registroDeInstruccion;
void mostrarError( string );

int main()
{
    Simpletron();
    mostrarMensajeInicioLMS();
    entradasLMS();
    ejecutar();
    return 0;
}

void Simpletron()
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

void mostrarMensajeInicioLMS()
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

void establecerMemoria( int contador, int entrada )
{
    memoria[ contador ] = entrada;
}

void entradasLMS()
{
     int entrada = 0;
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
             establecerMemoria( instruccion, entrada );
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
            establecerMemoria( instruccion, entrada );
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

void ejecutar()
{
    cout << "\n***Empieza la ejecucion del programa***\n"; //mensaje de inicio de ejecucion
    //bucle para ejecucion del programa
    while ( contadorInstrucciones < 100 )
    {
        registroDeInstruccion = memoria[ contadorInstrucciones ];
        LMS();
    }
}

void LMS()
{
    int palabra;

    //Divide la instruccion
    codigoDeOperacion = registroDeInstruccion / 100;
    operando = registroDeInstruccion % 100;
    ++contadorInstrucciones;

    switch ( codigoDeOperacion )
    {
    case LEE:
        cout << "\n0?:";
        cin >> palabra;
        if ( palabra <= 9999 && palabra >= -9999 )
        {
            memoria [ operando ] = palabra;
        }
        else
        {
            mostrarError( "fatal" );
        }
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
        if ( acumulador > 9999 || acumulador < -9999 )
        {
            mostrarError( "fatal" );
        }
        break;
    case RESTA:
        acumulador -= memoria[ operando ];
         if ( acumulador > 9999 || acumulador < -9999 )
        {
            mostrarError( "fatal" );
        }
        break;
    case DIVIDE:
        if ( memoria[ operando ] == 0 )
        {
            mostrarError( "divCero" );
        }
        acumulador /= memoria[ operando ];
        break;
    case MULTIPLICA:
        acumulador *= memoria[ operando ];
          if ( acumulador > 9999 || acumulador < -9999 )
        {
            mostrarError( "fatal" );
        }
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
        cout << "\n*** Termino la ejecucion de Simpletron ***" << endl;
        mostrarMemoria();
        contadorInstrucciones = 100;
        break;
    }
}
void mostrarMemoria()
{
    cout << "\n";
    cout << "REGISTROS:" << endl;
	cout << "accumulador:             " << showpos << setw( 5 ) << setfill( '0' ) << internal << acumulador << endl;
	cout << "contador        :        " << showpos << setw( 2 ) << setfill( '0' ) << internal << contadorInstrucciones << endl;
	cout << "registroDeInstruccion:   " << showpos << setw( 5 ) << setfill( '0' ) << internal << registroDeInstruccion << endl;
	cout << "codigoDeOperacion:       " << showpos << setw( 2 ) << setfill( '0' ) << internal << codigoDeOperacion << endl;
	cout << "operando:                " << showpos << setw( 2 ) << setfill( '0' ) << internal << operando << endl;
	cout << "\n" << endl;
	cout << "MEMORIA:" << endl;
	cout << "   0     1     2     3     4     5     6     7     8     9 " << endl;
	// Print out the memory block.
	cout << "00 ";
	for ( int i = 0; i < 10 ; i++ )
    {
		cout << showpos << setw( 5 ) << setfill( '0' ) << internal  << memoria[ i ] << " ";
	}
	cout << endl;
	for ( int s = 10; s < 100; s = s + 10 )
    {
		    cout << noshowpos << s << " ";
		    for ( int i = 0; i < 10; i++ )
		    {
			    cout << showpos << setw( 5 ) << setfill( '0' ) << internal  << memoria[ s+i ] << " ";
		    }
            cout << endl;
    }
}

void mostrarError( string codigoError )
{
  // Mensaje de error si obtiene valores mayores a 9999 y menores a -9999
  if ( codigoError.compare( "fatal" ) == 0 )
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
