#include <iostream>

using namespace std;

int numeroLlamadas = 0;

// Funcion que realiza un proceso simple
void funcionSimple() {
    cout << "Esta es una funcion simple que realiza un proceso basico." << endl;
    numeroLlamadas++;
}

// Funcion que devuelve la cantidad de veces que se llamo a funcionSimple
int devolverNumeroLlamadas() {
    return numeroLlamadas;
}

int main() {
    // Llamar a funcionSimple varias veces
    funcionSimple();
    funcionSimple();
    funcionSimple();

    cout << "La funcion 'funcionSimple' fue llamada " << devolverNumeroLlamadas() << " veces." << endl;

    return 0;
}
