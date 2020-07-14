// #include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
typedef long long int lld;
typedef long double llf;
typedef pair<int, int> pii;

const int MAXN = 12;

int n, m;
char arr[MAXN][MAXN];

// El tiempo minimo para llegar de (x, y) a 'E'
bool visitados[MAXN][MAXN];  // Falso todo inicialmente
int bfs(int x, int y) {
    queue<pair<int, int>> cola;
    cola.push({x, y});  // equiv = cola.push(make_pair(x, y))

    // Cómo sabemos el nivel???

    int t = 0;
    while (!cola.empty()) {
        // Todos los estados de la cola están en el nivel t en este punto
        // Necesito expandir todo mi nivel
        int sz = cola.size();
        for (int i = 0; i < sz; ++i) {
            // Obtener mi estado
            x = cola.front().first;
            y = cola.front().second;
            cola.pop();

            if (arr[x][y] == '#' || visitados[x][y] == true) {
                // Estado invalido o ya visitado
                continue;
            }
            visitados[x][y] = true;

            if (arr[x][y] == 'E') {
                // Ya terminamos
                return t;
            }

            // Estado intermedio
            // Necesitamos generar los siguientes estados
            cola.push({x, y + 1});
            cola.push({x, y - 1});
            cola.push({x + 1, y});
            cola.push({x - 1, y});
        }
        t++;
    }
    return -1;
}

int dfs(int x, int y) {
    stack<pair<pair<int, int>, int>> pila;
    pila.push({{x, y}, 0});

    while (!pila.empty()) {
        x = pila.top().first.first;
        y = pila.top().first.second;
        int t = pila.top().second;
        pila.pop();

        if (arr[x][y] == '#' || visitados[x][y] == true) {
            // Estado invalido o ya visitado
            continue;
        }
        visitados[x][y] = true;

        if (arr[x][y] == 'E') {
            // Ya terminamos
            return t;
        }

        // Estado intermedio
        // Necesitamos generar los siguientes estados
        pila.push({{x, y + 1}, t + 1});
        pila.push({{x, y - 1}, t + 1});
        pila.push({{x + 1, y}, t + 1});
        pila.push({{x - 1, y}, t + 1});
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }

    int t = dfs(x, y);

    cout << t << endl;
    return 0;
}