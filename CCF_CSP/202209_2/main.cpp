#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
#define N 300001
int f[N]{};
int dp[31][300010]{};
//转化成DP：带了x元，最多能买价值p元的数，f[x] = max(f[x], f[x-book_value]+bool_value);

int main() {
/*    int n, x, v, sum = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> v;
        sum += v;
        for (int j = sum; j >= v; j--) {
            f[j] = max(f[j], f[j - v] + v);
        }
    }

    for (int i = x; i <= sum; i++) {
        if (f[i] >= x){
            cout<<f[i];
            break;
        }
    }
    return 0;*/
    int n, x, v[30], sum = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= sum; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++) {
            if (j >= v[i - 1]) {
                dp[i][j] = max(max(dp[i - 1][j], dp[i][j]), dp[i - 1][j - v[i - 1]] + v[i - 1]);
            } else
                dp[i][j] = max(dp[i - 1][j], dp[i][j]);
        }

    for (int j = x; j <= sum; j++) {
        if (dp[n][j] >= x) {
            cout << dp[n][j];
            break;
        }
    }
}
