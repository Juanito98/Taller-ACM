#include <bits/stdc++.h>
using namespace std;

// Declaramos el número de filas y columnas de la matriz
int n, m;

// Declaramos la matriz (1)
int matriz[102][102];

// Esta función define una operación UP
void UP() {
	// Creamos una fila auiliar y la iniciamos con la primera fila de la matriz
	int fila[102];
	for (int i = 1; i <= m; i++) {
		fila[i] = matriz[1][i];
	}

	// Recorremos todas las filas desde la 2 hasta la n hacia arriba
	for (int i = 2; i <= n; i++) {
		// Cambiamos casilla por casilla de la i-ésima fila
		for (int j = 1; j <= m; j++) {
			matriz[i-1][j] = matriz[i][j];
		}
	}

	// Nuestra fila auxiliar la colocamos en la última fila
	for (int i = 1; i <= m; i++) {
		matriz[n][i] = fila[i];
	}
}

// Análogo a UP
void LEFT() {
	// Creamos una columna auiliar
	int columna[102];
	for (int i = 1; i <= m; i++) {
		columna[i] = matriz[i][1];
	}

	// Recorremos todas las columnas desde la 2 hasta la m hacia izquierda
	for (int j = 2; j <= m; j++) {
		// Cambiamos casilla por casilla de la j-ésima columna
		for (int i = 1; i <= n; i++) {
			matriz[i][j-1] = matriz[i][j];
		}
	}

	// Nuestra columna auxiliar la colocamos en la última columna
	for (int i = 1; i <= m; i++) {
		matriz[i][m] = columna[i];
	}
}

int main() {
	// Leemos las dimensiones de la matriz (2)
	cin >> n >> m;

	// Leemos la cantidad de operaciones
	int k;
	cin >> k;

	// Leemos las operaciones a realizar
	int ups = 0, lefts = 0;
	for (int i = 1; i <= k; i++) {
		// Obtenemos la i-ésima operación
		int op;
		cin >> op;

		if (op == 1) {
			// Es una operación UP
			ups++;
		} else if (op == 2) {
			// Es una operación DOWN (3)
			ups += n-1;
		} else if(op == 3) {
			// Es una operación LEFT
			lefts++;
		} else if(op == 4) {
			// Es una operación RIGHT (4)
			lefts += m-1;
		}
	}

	// Leemos la matriz de la entrada
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> matriz[i][j];
		}
	}

	// Sacamos módulo al número de operaciones (5)
	ups %= n;
	lefts %= m;

	// Ejecutamos las operaciones
	for (int i = 1; i <= ups; i++) {
		UP();
	}
	for (int i = 1; i <= lefts; i++) {
		LEFT();
	}

	// Imprimimos la matriz
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// Damos el formato que pide la salida (6)
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

/*
OBSERVACIONES
(1). Dado que declaramos la matriz globalmente, las casillas se inicializan
	con valor default; es decir, ceros.
(2). Hay que notar que nosotros solo usaremos las filas [1,n] y las
	columnas [1,m], dejando libres casillas de la matriz definida
(3). Una operación DOWN equivalen a n-1 operaciones UP
(4). Analogamente, una operación RIGHT equivale a m-1 operaciones LEFT
(5). Sabemos que hacer n operaciones UP es equivalente a no hacer ninguna
	operación. Analogamente, m operaciones left es equivalente a no hacer nada.
(6). Debemos imprimir un espacio (" ") cada que imprimimos las celdas de una fila
	y debemos imprimir un salto de línea (endl) por cada fila
*/
