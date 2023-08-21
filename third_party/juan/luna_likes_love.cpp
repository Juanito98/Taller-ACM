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

const int MAXN = 1000002;

int n;
int arr[MAXN];
int pos[MAXN];

struct bit {
    int tree[MAXN];

    int query(int pos) {
        int s = 0;
        for (; pos; pos -= pos & (-pos))
            s += tree[pos];
        return s;
    }

    int query(int i, int j) {
        return query(j) - query(i - 1);
    }

    void update(int pos, int v) {
        for (; pos < MAXN; pos += pos & (-pos))
            tree[pos] += v;
    }

} BIT;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(pos + 1, pos + n + 1, -1);

    lld ans = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        int x;
        cin >> x;
        if (pos[x] == -1) {
            pos[x] = i;
        } else {
            ans += (i - pos[x] - 1) - BIT.query(pos[x], i);
            ans ++; // Mandarlos a cita
            BIT.update(pos[x], 1);
            BIT.update(i, 1);
        }
    }

    cout << ans << "\n";

    return 0;
}