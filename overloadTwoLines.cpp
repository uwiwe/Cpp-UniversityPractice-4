#include <iostream>
using namespace std;

struct Coordenadas {
    float x;
    float y;
};

// Calcular la pendiente con la formula y2-y1/x2-x1 (m)
float calcularPendiente(Coordenadas p1, Coordenadas p2) {
    float m;
    if (p1.x == p2.x) { 
        return 1e9; // Representa pendiente indeterminada
    }

    m = (p2.y - p1.y) / (p2.x - p1.x);
    return static_cast<float>(m);
}

int calcularOrientacion(Coordenadas p, Coordenadas q, Coordenadas r) {
    float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0; // Son colineales
    return (val > 0) ? 1 : 2; // 1 para el giro horario y 2 para el giro antihorario
}

// Verificar si dos segmentos de linea se cruzan
int cruzanOParalelas(Coordenadas p1, Coordenadas p2, Coordenadas q1, Coordenadas q2, float m1, float m2) {
    // Calcular las orientaciones
    int o1 = calcularOrientacion(p1, p2, q1); // giro de p1-q1 respecto a q1
    int o2 = calcularOrientacion(p1, p2, q2); // giro de p1-q2 respecto a q2
    int o3 = calcularOrientacion(q1, q2, p1); // giro de q1-q2 respecto a p1
    int o4 = calcularOrientacion(q1, q2, p2); // giro de q1-q2 respecto a p2

    // Se cruzan si ambas condiciones se cumplen
    if (m1 * m2 == -1){
        return 1;
    } else if (m1 == m2){
        return 0;
    } else if (o1 != o2 && o3 != o4){
        return -1;
    } else {
        cout << "No se cumple ninguna de las condiciones esperadas." << endl;
        return 1e9;
    }
}

int main() {
    Coordenadas coordenada1_1, coordenada1_2, coordenada2_1, coordenada2_2;
    float m1, m2;

    cout << "Datos de la primera linea (se forma por dos puntos):" << endl;
    cout << "Ingrese la coordenada x del primer punto:" << endl;
    cin >> coordenada1_1.x;
    cout << "Ingrese la coordenada y del primer punto:" << endl;
    cin >> coordenada1_1.y;
    cout << "Ingrese la coordenada x del segundo punto:" << endl;
    cin >> coordenada1_2.x;
    cout << "Ingrese la coordenada y del segundo punto:" << endl;
    cin >> coordenada1_2.y;

    m1 = calcularPendiente(coordenada1_1, coordenada1_2);

    cout << "Datos de la segunda linea (se forma por dos puntos):" << endl;
    cout << "Ingrese la coordenada x del primer punto:" << endl;
    cin >> coordenada2_1.x;
    cout << "Ingrese la coordenada y del primer punto:" << endl;
    cin >> coordenada2_1.y;
    cout << "Ingrese la coordenada x del segundo punto:" << endl;
    cin >> coordenada2_2.x;
    cout << "Ingrese la coordenada y del segundo punto:" << endl;
    cin >> coordenada2_2.y;

    m2 = calcularPendiente(coordenada2_1, coordenada2_2);

    if (cruzanOParalelas(coordenada1_1, coordenada1_2, coordenada2_1, coordenada2_2, m1, m2) == -1) {
        cout << "La funcion devuelve -1. (Las lineas se cruzan)" << endl;
    } else if (cruzanOParalelas(coordenada1_1, coordenada1_2, coordenada2_1, coordenada2_2, m1, m2) == 0) {
        cout << "La funcion devuelve 0. (las lineas son paralelas)" << endl;
    } else if (cruzanOParalelas(coordenada1_1, coordenada1_2, coordenada2_1, coordenada2_2, m1, m2) == 1) {
        cout << "La funcion devuelve 1. (Las lineas son perpendiculares.)" << endl;
    }

    return 0;
}
