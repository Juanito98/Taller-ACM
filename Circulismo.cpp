//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

// Creamos una estructura de rango, que nos dirá 
// desde qué punto hasta qué punto cubre un círculo
struct rango {
    double inicio;
    double fin;
};

// Sobrecargamos el operador < para que sort() sepa cómo ordenar 
bool operator < (const rango& a, const rango& b) {
    return (a.inicio == b.inicio ? (a.fin < b.fin) : (a.inicio < b.inicio));
    /*
    Lo anterior se llama operador ternario,
    es equivalente a:
    
    if (a.inicio < b.inicio) {
        return true;
    }
    if (a.inicio > b.inicio) {
        return false;
    }
    if (a.fin < b.fin) {
        return true;
    }
    return false;
    */
}

// Nuestro arreglo de rangos
rango arr[10002]; // Hay a lo más 10000 rangos

int h, b, n;



int main() {

    // Leemos H, B, N
    cin >> h >> b >> n;

    // Leemos los círculos
    for (int i = 0; i < n; ++i) {
        // Leemos X y R del i-ésimo círculo
        int x, r;
        cin >> x >> r;
        
        // Solo nos interesa qué parte cubren de arriba
        if (2*r < h) {
            // En este caso no llega a cubrir nada de arriba
            // escribimos valores inútiles
            arr[i].inicio = -1;
            arr[i].fin = -1;
        } else {
            // Hacemos un poco de geometría (pitágoras)
            /*
            ------------- -> longitud
                        |
                        |   --> altura (H/2)
                        |
                        |
                        .-> Centro (x)
                        |
                        |
                        |
                        |
            -------------
            La diagonal es el radio
            Por lo tanto r^2 = (h/2)^2 + longitud^2
            */
            double altura = (double) (h) / 2.0;
            double longitud  = sqrt((double)(r*r) - altura*altura);
            arr[i].inicio = x - longitud;
            arr[i].fin = x + longitud;
        }
    }

    // Ordenamos por inicio, y luego por fin
    sort(arr, arr + n);

    // Empezamos a cubrir el lienzo
    int utilizados = 0; // cuántos círculos hemos utilizado
    double ultimoPuntoCubierto = 0; // inicialmente, no hemos cubrido nada
    int i = 0;
    while (ultimoPuntoCubierto < b) {
        // De todos los circulos que cubren el ultimoPuntoCubierto
        // elijo el que se extienda más a la derecha
        double masLejano = ultimoPuntoCubierto;
        while (i < n && arr[i].inicio <= ultimoPuntoCubierto) {
            masLejano = max(masLejano, arr[i].fin);
            i++;
        }
        if (masLejano <= ultimoPuntoCubierto) {
            // Esto quiere decir que ningún círculo cubrió más a la derecha
            break;
        }
        ultimoPuntoCubierto = masLejano;
        utilizados ++; // Utilizamos el circulo
    }

    if (ultimoPuntoCubierto >= b) {
        // Logramos cubrir todo el lienzo
        cout << utilizados << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}