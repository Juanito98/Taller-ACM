/*
    Tema: Búsqueda binaria
    Problema: ¿De cuánto nos toca?
    Link: https://omegaup.com/arena/IOI2017E1P3/practice/#problems/cuanto
    Ojo: si no los deja entrar, inicien sesión y hagan clic
            en iniciar concurso en https://omegaup.com/arena/IOI2017E1P3#problems 
            y vuelvan a picar en link del problema
*/
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

const int MAXN = 100002;

int N, A;  // n -> número de barras y a-> el número de amigos
int arr[MAXN];

// cuanto regresa cuántos barritas de chocolate de x cuadritos
// puedo formar de mis barras iniciales
int cuanto(int x) {
    int res = 0;
    for (int i = 0; i < N; ++i) {
        res += arr[i] / x;  // e.g. si arr[i] = 7, x = 3, puedo empaquetar 2 barritas de 3 cuadritos
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> A;

    // Leer N números
    int Nmax = 0;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        Nmax = max(Nmax, arr[i]);
    }

    // Empezar mi búsqueda binaria
    int l = 0, r = Nmax;
    while (l < r) {
        int med = (l + r + 1) / 2;
        if (cuanto(med) >= A) {
            // Sí puedo repartir med cuadritos a mis N amigos
            // [l, r] => [med, r]
            l = med;
        } else {
            // No puedo
            // [l, r] => [l, med-1]
            r = med - 1;
        }
    }
    // [.x] => [.]

    int ans = l;
    cout << ans << "\n";

    return 0;
}