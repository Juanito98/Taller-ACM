//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct par {
    int inicio;
    int fin;
};

// Sobrecargamos el operador < para que sort sepa como ordenar
bool operator <(const par& a, const par& b) {
    if (a.inicio < b.inicio) return true;
    if (a.inicio > b.inicio) return false;
    if (a.fin < b.fin) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // your code goes here
    int n = 6;

    // Inicializamos un arreglo de pares
    par arr[] = {{2, 3}, {3, 4}, {3, 4}, {-1, 2}, {9, 8}, {8, 7}};

    sort(arr, arr + n);  // Nlog N

    for (int i = 0; i < n; ++i) {
        cout << arr[i].inicio << " " << arr[i].fin << endl;
    }
    cout << endl;
    return 0;
}