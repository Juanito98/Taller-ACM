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

const int MAXN = 102;
int n;
int arr[MAXN][MAXN];

bool vis[MAXN][MAXN];
int memo[MAXN][MAXN];
/*
Dado la posición (i, j), quiero maximizar la puntuación de
algún camino hacia abajo 
*/
int dp(int i, int j) {
    if (i == n) {
        // Ya estoy en la última fila, no hay ya camino que decidir
        return arr[i][j];
    }
    if (!vis[i][j]) {
        vis[i][j] = true;
        // O bien me voy a la izquierda o bien a la derecha
        memo[i][j] = max(dp(i+1, j), dp(i+1, j+1)) + arr[i][j];
    }
    return memo[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> arr[i][j];
        }
    }

    cout << dp(1, 1) << "\n";

    return 0;
}