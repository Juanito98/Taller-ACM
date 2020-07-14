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

const int MAXN = 1000002;

int n;
int arr[MAXN];

stack<int> pila;
/*
pila.push(x)
pila.pop()
pila.top()
pila.empty()
*/

// Recuerden que trabajamos con índices
int encuentraMayor(int idx) {
    while (!pila.empty() && arr[pila.top()] <= arr[idx]) {
        pila.pop();
    }
    if (pila.empty()) {
        return -1;
    } else {
        return pila.top();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // Leemos arreglo
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int ans[n];
    // Empiezo proceso de derecha a izquierda
    for (int i = n - 1; i >= 0; --i) {
        ans[i] = encuentraMayor(i);
        pila.push(i);
    }

    for (int i = 0; i < n; ++i) {
        if (ans[i] != -1) ans[i]++;
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}