#include <limits.h>
#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
typedef long long int lld;
typedef long double llf;
typedef pair<int, int> pii;

lld suma(lld A[], int msc) {
    int i = 0;
    lld ans = 0;
    while (msc) {
        if (msc & 1) ans += A[i];
        msc >>= 1;
        i++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //const int LOG_N = 3;
    const int LOG_N = 13;
    //const lld BASE = 10;
    const lld BASE = 100000; // Mayor a LOG_N * MAXN
    //const lld GRANDE = 100;
    const lld GRANDE = 1e15;

    lld n;
    cin >> n;
    lld A[LOG_N + 1];
    lld S = 0;

    // Cosntruir A
    {
        lld curr = BASE;
        for (int i = 0; i < LOG_N; ++i) {
            cout << "?";
            for (lld j = 0; j < n; j++) {
                cout << " " << curr + j;
            }
            cout << endl;

            cin >> A[i];
            S += A[i];

            curr <<= 1;
        }
    }
    // El comodin
    {
        cout << "?";
        for (lld j = 0; j < n; j++) {
            cout << " " << GRANDE + j;
        }
        cout << endl;
        
        cin >> A[LOG_N];
        S += A[LOG_N];
    }

    // Construir la última pregunta
    vector<lld> lastQuery;
    for (int msc = (1 << LOG_N) - 1; lastQuery.size() < n && msc >= 0; --msc) {
        lld x = S - 2ll * suma(A, msc);
        if (x < GRANDE || x >= GRANDE + n) lastQuery.push_back(x);
    }

    // Pregunta 14
    cout << "?";
    for (int i = 0; i < n; ++i) {
        cout << " " << lastQuery[i];
    }
    cout << endl;
    
    lld y;
    cin >> y;

    // Reconstruye
    vector<lld> P;
    vector<lld> Q;
    {
        lld x = (S - y) / 2ll;
        int msc = x / BASE;
        P.push_back(y);
        for (int i = 0; i <= LOG_N; ++i) {
            if (msc & (1 << i)) P.push_back(A[i]);
            else Q.push_back(A[i]);
        }
    }

    // Responde
    cout << "! " << P.size() << " " << Q.size() << endl;
    for (int i = 0; i < P.size(); ++i) {
        cout << P[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < Q.size(); ++i) {
        cout << Q[i] << " ";
    }
    cout << endl;
    return 0;
}