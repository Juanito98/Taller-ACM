#include <iostream>
#include <string>
#include <utility>

typedef std::pair<int, int> pii;

pii query(const std::string& s) {
    std::cout << "? " << s << std::endl;
    std::cout.flush();
    int r, c;
    std::cin >> r >> c;
    return {r, c};
}

pii queryRight(int n, int m) {
    std::string s;
    // Vamonos a la columna m / 2 (techo)
    // Para eso, avanzamos m / 2 (piso)
    s += std::string(m / 2, '>');
    // Empezamos el algoritmo de ir
    // (m / 2) (piso) a la derecha
    // luego lo mismo a la izquierda
    for (int i = 0; i < n; ++i) {
        s += std::string((m - 1) / 2, '>');
        s += std::string((m - 1) / 2, '<');
        s += 'v';
    }
    return query(s);
}

pii queryLeft(int n, int m) {
    // Construyamos la query de la izquierda
    std::string s;
    // Vamonos otra vez columna m / 2
    s += std::string(m / 2, '>');
    // Bajamos igual pero ahora de izq a derecha
    for (int i = 0; i < n; ++i) {
        s += std::string((m - 1) / 2, '<');
        s += std::string((m - 1) / 2, '>');
        s += 'v';
    }
    // ahora, es seguro que estamos hasta abajo
    // con un bias
    // nos movemos (m + 1) / 2 a la izquierda
    // y todo arriba y así aseguramos terminar abajo de pared
    s += std::string((m + 1) / 2, '<');
    s += std::string(n, '^');
    return query(s);
}

pii queryL(int n, int m, int l) {
    std::string s = std::string(l, '>');
    s += std::string(n, 'v');
    return query(s);
}

pii solve(int n, int m) {
    // Buscamos en la mitad derecha
    pii q1 = queryRight(n, m);
    if (q1.first < n - 1) {
        // tenemos la pared exactamente abajo de nosotros
        return {q1.first + 1, q1.second};
    }
    if (q1.second == m / 2) {
        // Estamos en (n-1, m/2), nunca chocamos con pared
        // Entonces la respuesta está en la mitad izquierda
        pii q2 = queryLeft(n, m);
        if (q2.first > 0) {
            // Está arriba
            return {q2.first - 1, q2.second};
        } else {
            // Estaba en la ultima fila
            return {n - 1, q2.second - 1};
        }
    }
    // Tenemos que averiguar si la pared estuvo en la primera fila
    // o en la columna p1.second + ((m + 1) / 2)
    pii q3 = queryL(n, m, ((m + 1) / 2) + q1.second);
    if (q3.first < n - 1) {
        // Esta abajo
        return {q3.first + 1, q3.second};
    }
    // Estaba en la primera fila
    return {0, q3.second + 1};
}


int main() {
    int n, m;
    std::cin >> n >> m;
    pii sol = solve(n, m);
    std::cout << "! " << sol.first << " " << sol.second << std::endl;
    return 0;
}