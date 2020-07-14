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

    int n, k;

    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int res_ml = -1, res_no_botellas = 0;

    int necesito = 0;
    int i = n;
    for (int j = n - 1; j >= 0; j--) {
        // Cuántas botellas puedo enviar si las llevo a arr[j]

        // Antes de extender le pregunto
        while (i > 0 && necesito + (arr[j] - arr[i - 1]) <= k) {
            necesito += arr[j] - arr[i - 1];
            i--;
        }

        if (res_no_botellas <= j - i + 1) {
            res_no_botellas = j - i + 1;
            res_ml = arr[j];
        }

        // Me preocupo por j
        if (j > 0) {
            necesito -= (arr[j] - arr[j - 1]) * (j - i);
        }
    }

    cout << res_no_botellas << " " << res_ml << endl;
    return 0;
}