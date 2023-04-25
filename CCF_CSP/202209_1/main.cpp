#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[21], c[21], b[21];
    a[0] = 1;
    c[0] = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = c[i - 1] * a[i];

        int bi = (m % c[i] - sum) / c[i - 1];
        cout << bi << " ";
        sum += c[i - 1] * bi;
    }
    /*for (int i = n; i > 0; i--) {
        if (m >= c[i - 1]) {
            b[i] = ((m - c[i - 1]) + c[i - 1]) / c[i - 1];
            m -= b[i] * c[i - 1];
        } else
            b[i] = 0;
    }

    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";*/
}



