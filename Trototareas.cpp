#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
typedef long long int lld;
typedef long double llf;
typedef pair<lld, lld> pii;

const int MAXN = 502;
const int INF = 1000*500*2;

int n, S;
int valor[MAXN], tiempo[MAXN];

int memo[MAXN][MAXN]; // Aquí se guardan los calculados
bool vis[MAXN][MAXN];
int dp(int i, int j) {
    // Estoy en la iesima tarea y quiero sumar j
    if (j <= 0) {
        return 0;
    }
    if (i <= 0) {
        // Ya me acabe mis tareas y j > 0
        return INF;
    }
    if (!vis[i][j]) {
        // Calculo la respuesta para el estado
        // minimo entre no tomar y tomar
        memo[i][j] = min(dp(i-1, j), dp(i-1, j-valor[i]) + tiempo[i]);
        vis[i][j] = true;
    }
    return memo[i][j];
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> S;
    for (int i = 1; i <= n; ++i) {
        cin >> valor[i] >> tiempo[i];
    }
    cout << dp(n, S) << "\n";

    return 0;
}