#include <iostream>
using namespace std;

int main() {
    /*
    n
    a1 a2 a3... an
    */

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mejorSuma = 0;
    
    int i = 0, j = 0; // [i, j)
    int sumaAct = 0;

    while (i < n) {
        while (j < n && sumaAct >= 0) {
            sumaAct += arr[j]; // i j 
            mejorSuma = max(mejorSuma, sumaAct);
            j++;
        }
        // suma [i, j) sea negativo
        i = j;
        sumaAct = 0;
    }

    cout << mejorSuma << "\n";

    return 0;
}