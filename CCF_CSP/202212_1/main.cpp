#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    double i;
    cin >> n >> i;
    double sum = 0, s;
    for (int j = 0; j <= n; j++) {
        sum *= (1 + i);
        cin >> s;
        sum += s;
    }
    for (int j = 0; j < n; j++)
        sum /= (1 + i);
    printf("%f", sum);
}
