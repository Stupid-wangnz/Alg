#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
double Q[8][8]{};
double M[8][8]{};
double resM[8][8]{};

double alpha(double x) {
    if (x == 0)
        return pow(0.5, 0.5);
    return 1;
}

double ReTran(int i, int j) {
    double res = 0;
    for (int u = 0; u < 8; u++) {
        for (int v = 0; v < 8; v++) {
            res += alpha(u) * alpha(v) * M[u][v] * cos((acos(-1) / 8) * (i + 0.5) * u) *
                   cos((acos(-1) / 8) * (j + 0.5) * v);
        }
    }
    return res / 4;
}

int main() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            cin >> Q[i][j];
        }

    int n, T;
    cin >> n >> T;
    vector<int> encode;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        encode.push_back(t);
    }

    int x = 0, y = 0, xl = 1, idx = 0;

    while (idx != encode.size()) {
        M[x][y] = encode[idx];
        idx++;
        if (x == 0 && xl == 1) {
            y++;
            xl = -1;
            continue;
        }
        if (y == 0 && xl == -1) {
            x++;
            xl = 1;
            continue;
        }
        x -= xl;
        y += xl;
    }

    if (T == 0) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
                cout << M[i][j] << " ";
            cout << endl;
        }
        return 0;
    }

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            M[i][j] *= Q[i][j];


    if (T == 1) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
                cout << M[i][j] << " ";
            cout << endl;
        }
        return 0;
    }

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            resM[i][j] = ReTran(i, j) + 128;


    if (T == 2) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
                cout << (resM[i][j] >= int(resM[i][j]) + 0.5 ? int(resM[i][j]) + 1 : int(resM[i][j]) )<< " ";
            cout << endl;
        }
    }
    return 0;
}
