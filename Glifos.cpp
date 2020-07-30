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

int n, m;
string s, t;

const int MAX_ALF = 60;
int bucket_S[MAX_ALF]; // Fija
int bucket_T[MAX_ALF]; // Vamos a andar modificando
int errores = 0;

int charToIdx(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A' + ('z' - 'a' + 1);
}

void update(char c, int v) {
    // 1 -> mete, -1 -> saca
    int idx = charToIdx(c);
    if (bucket_S[idx] == bucket_T[idx]) {
        // Eran igual, ya no lo seran
        errores++;
    }
    bucket_T[idx] += v;
    if (bucket_S[idx] == bucket_T[idx]) {
        // Eran diferentes, pero ahora son iguales
        errores--;
    }
}

int barrido() {
    int i = 0, j = 0;
    for (j = 0; j < n; ++j) {
        update(t[j], 1);
    }
    j--;
    int ans = 0;
    while (j < m) {
        //cout << i << " " << j << " " << errores << endl;
        if (errores == 0) {
            // Ya hay un match
            ans++;
        }
        if (j < m-1) {
            // deslizar la ventana
            update(t[j+1], 1);
            update(t[i], -1);
        }
        i++;
        j++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> s >> t;

    for (char c : s) {
        int idx = charToIdx(c);
        if (bucket_S[idx] == 0) {
            errores++;
        }
        bucket_S[idx]++;
    }

    cout << barrido() << "\n";

    return 0;
}