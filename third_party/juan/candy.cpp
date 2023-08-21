#include <iostream>

typedef long long lld;

const int MAXN = 102;
const int MAXF = 102;

int N, F;
lld T;
lld arr[MAXN];

/* DP (ops, i, j)
The maximum sum we can get placing F candies at the very beginning
- ops: Number of ops allowed
- i: the index of the candy we are deciding to be in the first F
- j: the number of candies we have already placed
*/
lld memo[MAXN * MAXF][MAXN][MAXF];
bool vis[MAXN * MAXF][MAXN][MAXF];
lld maxSum(lld ops, int i = 0, int j = 0) {
    if (j > i || j > F) {
        // Something went wrong
        return -1;
    }
    if (ops < 0) {
        // We have no more ops left
        return -1;
    }
    if (j == F) {
        // We have already placed F candies
        return 0;
    }
    if (i >= N) {
        // We did not place F candies. -1 invalid answer
        return -1;
    }
    // We can either place the candy i in the first F or not
    if (!vis[ops][i][j]) {
        vis[ops][i][j] = true;
        lld notTake = maxSum(ops, i + 1, j);
        // Take it. i - j is the number of ops we need to place the candy i in the jth position
        lld take = maxSum(ops - (i - j), i + 1, j + 1);
        if (take != -1) {
            take += arr[i];
        }
        memo[ops][i][j] = std::max(notTake, take);
    }
    return memo[ops][i][j];
}

int main() {
    std::cin >> N >> F >> T;
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }
    int ops = 0;
    for (ops = 0; maxSum(ops) < T && ops < N * F; ++ops);
    if (maxSum(ops) < T) {
        std::cout << "NO\n";
    } else {
        std::cout << ops << '\n';
    }
    return 0;
}
