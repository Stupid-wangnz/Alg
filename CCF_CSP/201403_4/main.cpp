#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, k;
long long r;

class Router {
public:
    long long x = 0, y = 0;
    int num = 0;
    vector<int> accessibleRouters;
    int kCount = 0;
    int jumpTime = INT32_MAX;
    bool visited = false;

    Router(long x, long y, int num) {
        this->x = x;
        this->y = y;
        this->num = num;
    }

    void addAccessible(int num) {
        this->accessibleRouters.push_back(num);
    }
};

vector<Router> routers;

long long distance(Router r1, Router r2) {
    return (r1.x - r2.x) * (r1.x - r2.x) + (r1.y - r2.y) * (r1.y - r2.y);
}

void RouterSPFA(Router tar) {
    queue<Router> q;
    q.push(tar);
    while(!q.empty()){
        Router cur = q.front();
        q.pop();
        cur.visited = false;
        for (int i = 0; i < cur.accessibleRouters.size(); i++) {
            Router *router = &routers[cur.accessibleRouters[i]];

            if (cur.kCount >= k && router->num > n)
                continue;

            if (router->jumpTime > cur.jumpTime + 1)
                router->jumpTime = cur.jumpTime + 1;
            if (!router->visited){
                router->visited = true;
                if (router->num > n) {
                    router->kCount++;
                }
                q.push(*router);
            }
        }
    }
}

void RouterBFS(Router tar) {
    queue<Router> q;
    q.push(tar);
    while(!q.empty()){
        Router cur = q.front();
        q.pop();
        for (int i = 0; i < cur.accessibleRouters.size(); i++) {
            Router *router = &routers[cur.accessibleRouters[i]];
            if (cur.kCount >= k && router->num > n)
                continue;

            if (router->jumpTime > cur.jumpTime + 1) {
                router->jumpTime = cur.jumpTime + 1;
                if (router->num > n) {
                    router->kCount++;
                }
                q.push(*router);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k >> r;
    for (int i = 0; i < n + m; i++) {
        long long x, y;
        cin >> x >> y;
        Router newRouter(x, y, i);
        for (int j = 0; j < i; j++) {
            if (distance(newRouter, routers[j]) <= r * r) {
                newRouter.addAccessible(j);
                routers[j].addAccessible(i);
            }
        }
        routers.push_back(newRouter);
    }

    if (distance(routers[0], routers[1]) <= r * r) {
        cout << 0;
        return 0;
    }
    routers[1].jumpTime = 0;
    //RouterSPFA(routers[1]);
    //cout << routers[0].jumpTime -1;
    RouterBFS(routers[1]);
    cout << routers[0].jumpTime -1;
}
