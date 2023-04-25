#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>

using namespace std;

int dis[100000]{};

class myDis {
public:
    pair<int, int> d;

    myDis() {
        d.first = 1000000000;
        d.second = 100000;
    }

    bool operator<(const myDis &b) const {
        return (double(this->d.second) - double(b.d.second)) < log(double(b.d.first) / double(this->d.first));
    }

    myDis operator+(const myDis &b) const {
        myDis t;

        if (this->d.second < b.d.second) {
            t.d.first = this->d.first;
            t.d.second = this->d.second;
            t.d.first += b.d.first * pow(2, this->d.second - b.d.second);
        } else {
            t.d.first = b.d.first;
            t.d.second = b.d.second;
            t.d.first += this->d.first * pow(2, b.d.second - this->d.second);
        }
    }
};

myDis world[100000][100000]{};

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l1, l2, r1, r2, a, b;
        cin >> l1 >> r1 >> l2 >> r2 >> a >> b;
        for (int x = l1; x <= l2; x++)
            for (int y = r1; y <= r2; y++) {
                world[x][y].d.first = a;
                world[x][y].d.second = b;
            }
    }
    for (int i = 0; i < m; i++)
        dis[i] = INT_MAX;
    map<int, myDis> map_dis;
    map_dis[0] = myDis();
    while (map_dis.size() != m) {
        myDis minD;
        int minI = 0;
        for (int i = 1; i < m; i++) {
            if (map_dis.count(i))
                continue;
            if (world[0][i] < minD) {
                minD = world[0][i];
                minI = i;
            }
        }
        map_dis[minI] = world[0][minI];

        for (int i = 1; i < m; i++) {
            if (map_dis.count(i))
                continue;
            if (world[0][i] < world[minI][i] + minD)
                world[0][i] = world[minI][i] + minD;
        }
    }

    for(int i=1;i<m;i++){

    }


}
