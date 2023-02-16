#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 1000
#define MAX_STATE_COUNT  6
#define MOD 1000000007
//s1 = {2}, s2 = {2, 0}, s3 = {2, 3}, s4 = {2, 0, 1}, s5 = {0, 2, 3}, s6 = {0, 1, 2, 3}
long long dp[MAXN + 1][MAX_STATE_COUNT];

//state DP problem
int main() {
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));

    dp[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][3] = (dp[i - 1][1] + dp[i - 1][3] * 2) % MOD;
        dp[i][4] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] * 2) % MOD;
        dp[i][5] = (dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5] * 2) % MOD;
    }
    cout << dp[n][5];
}
