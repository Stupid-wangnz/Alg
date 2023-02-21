#include <iostream>
#include <vector>

using namespace std;
//O(mn)方法超时，暴力算法70分
/*struct plan {
    int t, c;

    plan(int t, int c) {
        this->t = t;
        this->c = c;
    };

    plan() {};
};

plan plans[100001];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int ti, ci;
    for (int i = 0; i < n; i++) {
        cin >> ti >> ci;
        plan p(ti, ci);
        plans[i] = p;
    }
    int qi;
    for (int i = 0; i < m; i++) {
        cin >> qi;
        int st = qi + k, ed;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (plans[j].t < st)
                continue;
            ed = st + plans[j].c - 1;
            if (plans[j].t <= ed)
                count++;
        }
        cout << count << endl;
    }
}*/
//差分算法，计算出每一个场所的区间如下：
//              q+k<=ti,q+k+ci-1>=ti
//              ti-k-ci+1<=q<=ti-k
#define N 200005
int q[N]{};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int ti, ci, r, l;
    for (int i = 0; i < n; i++) {
        cin >> ti >> ci;
        l = max(1, ti - k - ci + 1);
        r = max(1, ti - k + 1);
        q[l]++;
        q[r]--;
    }
    for (int i = 1; i < N; i++)
        q[i] += q[i - 1];
    for (int i = 0; i < m; i++) {
        int qi;
        cin >> qi;
        cout << q[qi] << endl;
    }
}