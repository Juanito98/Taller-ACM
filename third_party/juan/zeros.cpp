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

lld a, b;

int mayorPot(int x) {
    int ans = 0;
    for (lld num = x, pot = 1; num <= b; num *= x, ++pot) {
        lld div = (a + num - 1) / num;
        if (div * num <= b) ans = pot;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    int dos = mayorPot(2);
    int cinco = mayorPot(5);

    cout << min(dos, cinco) << "\n";

    return 0;
}