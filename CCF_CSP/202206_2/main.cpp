#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Tree {
public:
    int x, y;

    Tree(int x, int y) : x(x), y(y) {};

    Tree() {};

    bool operator==(const Tree &t) {
        return this->x == t.x && this->y == t.y;
    }
};

class TreeCompare {
public:
    bool operator()(Tree &t1, Tree &t2) {
        if (t1.x != t2.x)
            return t1.x < t2.x;
        return t1.y < t2.y;
    }
};

class MAP {
public:
    vector<Tree> Trees;
};

bool SMAP[51][51]{};

bool check(int x, int y, int S, MAP m) {
    for (int i = 0; i <= S; i++)
        for (int j = 0; j <= S; j++) {
            Tree tt(i + x, j + y);
            if (SMAP[i][j]) {
                if (find(m.Trees.begin(), m.Trees.end(), tt) == m.Trees.end()) {
                    return false;
                }
            } else {
                if (find(m.Trees.begin(), m.Trees.end(), tt) != m.Trees.end()) {
                    return false;
                }
            }
        }
    return true;
}

int main() {
    int n, L, S;
    cin >> n >> L >> S;
    int x, y;
    MAP m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        Tree t(x, y);
        m.Trees.push_back(t);
    }
    sort(m.Trees.begin(), m.Trees.end(), TreeCompare());
    for (int i = 0; i <= S; i++)
        for (int j = 0; j <= S; j++)
            cin >> SMAP[S - i][j];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        Tree t = m.Trees[i];
        if (t.x <= L - S && t.y <= L - S) {
            if (check(t.x, t.y, S, m))
                sum++;
        }
    }
    cout << sum;
};


/*bool **GMAP, **SMAP;

bool check(int x, int y, int S) {
    for (int i = 0; i <= S; i++)
        for (int j = 0; j <= S; j++) {
            if (GMAP[i + x][j + y] != SMAP[i][j])
                return false;
        }
    return true;
}

int main() {
    int n, L, S;
    cin >> n >> L >> S;
    GMAP = new bool *[L + 1];
    for (int i = 0; i <= L; i++) {
        GMAP[i] = new bool[L + 1];
        memset(GMAP[i], 0, L);
    }
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        GMAP[x][y] = true;
    }


    SMAP = new bool *[S + 1];
    for (int i = 0; i <= S; i++)
        SMAP[i] = new bool[S + 1];
    for (int i = 0; i <= S; i++)
        for (int j = 0; j <= S; j++)
            cin >> SMAP[S - i][j];
    int sum = 0;
    for (int i = 0; i <= L - S; i++)
        for (int j = 0; j <= L - S; j++) {
            if (GMAP[i][j]) {
                if (check(i, j, S))
                    sum++;
            }
        }
    cout << sum << endl;
}*/
