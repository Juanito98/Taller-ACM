#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

typedef long long int lld;


int main() {
    // Variables de entrada
    int n;
    std::unordered_map<lld, int> arr; // notar que no nos importa el orden
    
    // Variable donde guardamos la inflación acumulada en los Q días
    lld cumulatedInflation = 0;
    // Variable donde guardaremos la suma de todos los elementos
    lld S = 0;

    // Leemos la entrada
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        arr[x] += 1;
        S += x;
    }

    // Procesamos las Q consultas
    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; ++i) {
        std::string t;
        lld x;
        std::cin >> t >> x;
        if (t == "INFLATION") {
            cumulatedInflation += x;
            // Actualizamos la suma de todos los elementos
            S += n * x;
        } else {
            // Todos los precios que estaban en x ahora están en y
            // Nos falta leer y
            lld y;
            std::cin >> y;
            // Para esto necesitamos el precio x sin inflacion acumulada
            lld xWithoutInflation = x - cumulatedInflation;
            S -= arr[xWithoutInflation] * xWithoutInflation;
            // Se actualizan al valor y sin inflación acumulada
            lld yWithoutInflation = y - cumulatedInflation;
            S += arr[xWithoutInflation] * yWithoutInflation;

            // Actualizamos el arreglo
            if (x != y) {
                arr[yWithoutInflation] += arr[xWithoutInflation];
                arr[xWithoutInflation] = 0;
            }
        }
        // Imprimimos la suma acumulada
        std::cout << S << std::endl;
    }
    return 0;
}