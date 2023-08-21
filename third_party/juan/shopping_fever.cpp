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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    int arr[n];

    lld S = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        S += arr[i];
    }
    sort(arr, arr + n);

    lld dp[n]; // Regresa el mayor descuento de los primeros n

    for (int i = 0; i < n; ++i) {
        lld desc1 = 0;
        if (i >= 2) desc1 += arr[i-2];
        if (i > 2) desc1 += dp[i-3];

        lld desc2 = (arr[i] * q) / 100;
        if (i > 0) desc2 += dp[i-1];

        dp[i] = max(desc1, desc2);
    }

    cout << S - dp[n-1] << "\n"; 

    return 0;
}