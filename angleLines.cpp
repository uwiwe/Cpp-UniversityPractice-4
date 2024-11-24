#include <iostream>
#include <cmath>

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

// Funcion para calcular el angulo entre dos lineas
double calcularAngulo(double m1, double m2, bool enGrados = false) {
    // Calcula el angulo en radianes usando la formula arctan(|(m2 - m1) / (1 + m1 * m2)|)
    double angulo = atan(abs((m2 - m1) / (1 + m1 * m2)));
    
    if (enGrados) {
        angulo = angulo * (180.0 / M_PI);
    }
    
    return angulo;
}

int calcularOrientacion(Coordenadas p, Coordenadas q, Coordenadas r) {
    float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Verificar si dos segmentos de linea se cruzan
int cruzanOParalelas(Coordenadas p1, Coordenadas p2, Coordenadas q1, Coordenadas q2) {
    // Calcular las orientaciones
    int o1 = calcularOrientacion(p1, p2, q1); // giro de p1-q1 respecto a q1
    int o2 = calcularOrientacion(p1, p2, q2); // giro de p1-q2 respecto a q2
    int o3 = calcularOrientacion(q1, q2, p1); // giro de q1-q2 respecto a p1
    int o4 = calcularOrientacion(q1, q2, p2); // giro de q1-q2 respecto a p2

    // Se cruzan si ambas condiciones se cumplen
    if (o1 != o2 && o3 != o4){
        return 1;
    }

    return 0;
}

int main() {
    Coordenadas coordenada1_1, coordenada1_2, coordenada2_1, coordenada2_2;
    float m1, m2;
    bool enGrados;

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

    cout << "Quieres el angulo en grados? Por defecto se te dara en radianes. (1 para si, 0 para no): ";
    cin >> enGrados;

    double angulo = calcularAngulo(m1, m2, enGrados);

    if (cruzanOParalelas(coordenada1_1, coordenada1_2, coordenada2_1, coordenada2_2) == 0) {
        cout << "No se puede calcular el angulo entre las dos lineas debido a que las lineas no se cruzan. Si usted cree que esto es un error, puede significar que sus lineas se solapan." << endl;
    } else if (enGrados) {
        cout << "El angulo entre las lineas es: " << angulo << " grados.\n";
    } else {
        cout << "El angulo entre las lineas es: " << angulo << " radianes.\n";
    }

    return 0;
}
