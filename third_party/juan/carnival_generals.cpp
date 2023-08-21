#include <iostream>
#include <unordered_set>
#include <vector>

bool invalid_general(std::vector<int>& arr, int pos, std::unordered_set<int>& cantSitWith) {
    // Si el general en la posición pos tiene vecinos 
    // con los que no puede sentarse, entonces es invalido
    bool rightInvalid = false;
    bool leftInvalid = false;
    if (pos + 1 < arr.size()) {
        rightInvalid = cantSitWith.count(arr[pos + 1]);
    }
    if (pos > 0) {
        leftInvalid = cantSitWith.count(arr[pos - 1]);
    }
    return rightInvalid || leftInvalid;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> ans;
    std::unordered_set<int> cantSitWith;
    for (int i = 0; i < n; ++i) {
        // Acomodar el general i
        cantSitWith.clear();
        for (int k = 0; k < i; ++k) {
            int j; // El general j está rankeado en k
            std::cin >> j;
            // Si es parte de la segunda mitad, entonces no puedo sentar
            // a i con él
            if (k >= (i + 1) / 2) {
                cantSitWith.insert(j);
            }
        }
        // Lo siento en la primera posición valida
        // Haciendo insertion sort
        ans.push_back(i);
        int general_pos = ans.size() - 1;
        while (invalid_general(ans, general_pos, cantSitWith)) {
            std::swap(ans[general_pos], ans[general_pos - 1]);
            general_pos -= 1;
        }
    }
    // Imprimir la respuesta
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " ";
    }
    return 0;
}