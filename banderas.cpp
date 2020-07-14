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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*
    n Q
    Q líneas de la forma [i, j], v
    */

    int n, Q;
    cin >> n >> Q;

    int bucket[n + 1];
    fill(bucket, bucket + n + 1, 0);

    for (int q = 0; q < Q; ++q) {
        int i, j, v;
        cin >> i >> j >> v;
        bucket[i] += v;
        bucket[j + 1] -= v;
    }

    int arr[n + 1];

    arr[0] = 0;
    for (int i = 1; i <= n; ++i) {
        // arr[i] es la suma de las banderas que afectaron de [1, i]
        // Es decir es la suma de bucket[1] + bucket[2] + ... + bucket[i]
        arr[i] = arr[i - 1] + bucket[i];
    }

    // Imprimimos el arreglo
    for (int i = 1; i <= n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}