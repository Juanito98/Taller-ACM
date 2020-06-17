/*
Link del problema: https://omegaup.com/arena/problem/L-OMI2010-Vueltas/#problems
Idea:
    - Leer el tablero
    - Contar las operaciones
    - Aplicar h % 2 operaciones horizontales
    - Aplicar v % 2 operaciones verticales
    - Imprimir el resultado
*/
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

// Variables globales
int n, m, k; // n->filas m->columnas
int matriz[1002][1002];

// <tipo de dato de retorno> <nombre>(<variables>) {} 

void operacionHorizontal() {
    // matriz 5 columnas [0, 1, 2, 3, 4]
    // [0, n-1], [1, n-2], ... [pivote-1, pivote+1]
    int pivote = m / 2;
    for (int j = 0; j < pivote; j++) {
        // intercambiar columna j con columna m-j-1
        for (int i = 0; i < n; i++) {
            swap(matriz[i][j], matriz[i][m-j-1]);
        }
    }
}

void operacionVertical() {
    int pivote = n / 2;

    /*
    int a = 2, b = 3;
    swap(a, b);
    // a = 3, b= 2
    */

    for (int i = 0; i < pivote; i++) {
        // intercambio fila i con fila n-i-1
        for (int j = 0; j < m; j++) {
            swap(matriz[i][j], matriz[n-i-1][j]);
        }
    }
}

int main() {
    /*
    bool flag = false;
    int entero = -20; // 2* 1e9
    unsigned int sinSigno = 20;
    float doble = 20.4;
    double masPrecision = 20.2334455;
    long long int enteroGrande = 1e18;
    char f = 'r';

    int arr[5]; // [_, _, _, _ ,_] indexado en 0
    int matriz[5][5];
   string cadena; // char[]
    */
   cin >> n >> m;
   
   for (int i = 0; i < n; i++) {
       // i = 0, 1, 2, ..., n-1
       // i esima fila
       // i++, ++i => i = i + 1
       for (int j = 0; j < m; j++) {
           // j esima columna
           cin >> matriz[i][j];
       }
   }
    cin >> k;

    int h = 0, v = 0;
    for (int i = 0; i < k; i++) {
        char op;
        cin >> op;
        if (op == 'V') {
            // es vertical
            v++; // v = v + 1
        } else {
            // es horizontal
            h++;
        }
    }

    if ((h % 2) == 1) {
        // aplicar
        operacionHorizontal();
    }

    if ((v % 2) == 1) {
        operacionVertical();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    } 


    return 0;
}