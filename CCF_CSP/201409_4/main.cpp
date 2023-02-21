#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dis[1001][1001]{};
bool visited[1001][1001]{};
int consumer[1001][1001]{};
int numOfAddr = 0;
int n;
long long sumOfStep = 0;

class node {
public:
    int x, y, distance;

    node(int x, int y, int distance) : x(x), y(y), distance(distance) {};
};

queue<node> q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void BFS() {
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.x + dx[i], y = cur.y + dy[i];
            if (x <= 0 || x > n || y <= 0 || y > n || visited[x][y]) continue;
            if (consumer[x][y]) {
                sumOfStep = sumOfStep + consumer[x][y] * (cur.distance + 1);
                numOfAddr--;
                if (!numOfAddr)
                    return;
            }
            node next(x, y, cur.distance + 1);
            q.push(next);
            visited[x][y] = true;
        }
    }
}

int main() {
    int m, k, d;
    cin >> n >> m >> k >> d;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        node n(x, y, 0);
        visited[x][y] = true;
        q.push(n);
    }
    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        if (consumer[x][y] == 0)
            numOfAddr++;
        consumer[x][y] += c;
    }
    for (int i = 0; i < d; i++) {
        int x, y;
        cin >> x >> y;
        visited[x][y] = true;
    }
    BFS();
    cout << sumOfStep;
}
