#include <iostream>
#include <utility>
#include <map>
#include <vector>

typedef std::pair<int, int> pii;

const int MAXN = 200000;
const int MAXM = MAXN;

int n, m;
pii matches[MAXM];

/*
Una arista (i, j) quiere decir una conexion de la medalla
i a la medalla j
*/
std::vector<int> adj[MAXM];

// El primer owner de la medalla (en el dia=medalla)
int firstOwner[MAXM];
// El tiempo que el first owner tuvo la medalla
int firstOwnerDuration[MAXM];

// El tiempo en el que el participante pierde su siguiente match
int nextMatchLost[MAXM];


// Quién se quedó con la medalla al final
int winnerOfMedal[MAXM];
bool calculatedWinnerOfMedal[MAXM];

void printInfo(int medal, const std::map<int, int>&T) {
    std::cout << "----------- Medalla " << medal << "--------------\n";
    std::cout << "El primer owner fue " << firstOwner[medal] << " y tuvo la medalla " << firstOwnerDuration[medal] << " noches\n";
    for (auto p : T) {
        if (p.second == 0) continue;
        std::cout << "El participante " << p.first << " tuvo la medalla " << p.second << " noches." << std::endl;
    }
    std::cout << "El ganador fue " << winnerOfMedal[medal] << std::endl;
}

std::map<int, int> T;
void dfs(int medal, int currentWinner = 0, bool verbose = false) {
    // Actualizamos el tiempo que tuvo la medalla el primer owner
    T[firstOwner[medal]] += firstOwnerDuration[medal];
    if (T[firstOwner[medal]] > T[currentWinner] || (T[firstOwner[medal]] == T[currentWinner] && firstOwner[medal] < currentWinner)) {
        winnerOfMedal[medal] = firstOwner[medal];
    } else {
        winnerOfMedal[medal] = currentWinner;
    }
    calculatedWinnerOfMedal[medal] = true;
    if (verbose) {
        printInfo(medal, T);
    }
    for (int h : adj[medal]) {
        // Nos propagamos
        dfs(h, winnerOfMedal[medal]);
    }
    // Regresamos el map a su estado inicial
    T[firstOwner[medal]] -= firstOwnerDuration[medal];
}

int medalCount[MAXN];

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        matches[i] = {a, b};
    }

    // Calculamos la lista de adyacencia
    for (int medal = m - 1; medal >= 0; medal--) {
        int a, b;
        a = matches[medal].first;
        b = matches[medal].second;

        firstOwner[medal] = a; // El primer owner de la medalla
        
        // Para este match veamos cuando el first owner
        // pierde la medalla nueva (y las viejas que vaya a adquirir)
        int timeMedalIsLost = nextMatchLost[a];
        if (!timeMedalIsLost) {
            // La medalla no se pierde nunca
            firstOwnerDuration[medal] = m - medal;
        } else {
            firstOwnerDuration[medal] = timeMedalIsLost - medal;
            // De alguna manera conectamos a la medalla
            // con la nueva en timeMedalIsLost
            adj[timeMedalIsLost].push_back(medal);
        }

        nextMatchLost[b] = medal;
    }

    // Se forma uno o varios arboles donde podemos
    // calcular la respuesta con dfs desde las raíces
    for (int nodo = m - 1; nodo >= 0; nodo--) {
        if (!calculatedWinnerOfMedal[nodo]) {
            dfs(nodo);
        }
    }

    // Calculamos cuántas medallas ganó cada participante
    for (int medal = 0; medal < m; ++medal) {
        medalCount[winnerOfMedal[medal]]++;
    }
    
    for (int i = 0; i < n; ++i) {
        std::cout << medalCount[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}