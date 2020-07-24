#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <iomanip>
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

const int MAXN = 500002;

int N, R;
lld K;

lld defensa[MAXN];

lld minRequerido(lld d) {
    lld necesito = 0;

    lld curr = 0;  // ya puse y siguen vigentes
    lld eventos[N];
    fill(eventos, eventos + N, 0);

    for (int i = 0; i < N && /* PARCHE*/ necesito <= K; ++i) {
        // Necesito procesar eventos
        curr += eventos[i];

        if (defensa[i] + curr < d) {
            // Necesito poner más arqueros
            // cuantos?
            lld new_arqueros = d - (defensa[i] + curr);
            necesito += new_arqueros;

            // Modifico eventos porque llegan new_arqueros [i, i+2r]
            // Porque los estoy poniendo en i+r
            // Ya proceso que llego arqueros
            curr += new_arqueros;
            // Añado evento de que se van (ya no cubren esos arqueros)
            if (i + 2 * R + 1 < N) {
                eventos[i + 2 * R + 1] -= new_arqueros;
            } else {
                // A partir de aquí todos estos serán activos por lo que resta
                // de las secciones
                // DO NOTHING
            }
        }
    }

    return necesito;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> K;
    lld arqueros[N];
    for (int i = 0; i < N; ++i) {
        cin >> arqueros[i];
    }

    lld pre[N];  // suma de 0 a i
    pre[0] = arqueros[0];
    for (int i = 1; i < N; ++i) {
        pre[i] = pre[i - 1] + arqueros[i];
    }

    for (int i = 0; i < N; ++i) {
        // defensa es suma [i-r, i+r] (fixed)
        int l = max(0, i - R);
        int r = min(N - 1, i + R);
        //suma de l a r
        if (l == 0)
            defensa[i] = pre[r];
        else
            defensa[i] = pre[r] - pre[l - 1];
    }

    // Binaria para buscar d chida
    lld l = 0, r = (lld)(1e9) * (lld)(N) + K + 1ll;
    while (l < r) {
        lld med = (l + r + 1) / 2;  // d que vamos a probar
        // [s, s, s, (s, n), n, n, n]
        if (minRequerido(med) <= K) {
            l = med;  // [l, r] => [med, r]
        } else {
            r = med - 1;  // [l, r] => [l, med-1]
        }
    }
    cout << l << "\n";
    return 0;
}