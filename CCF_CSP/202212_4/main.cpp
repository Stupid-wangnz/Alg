#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    vector<Node *> childs;
    int ax;

    vector<int> collect;

    Node() {};

    int Ans() {
        int sum = 0;
        if (collect.size() == 1)
            return 0;
        for (int i = 0; i < collect.size(); i++) {
            int minnum = INT_MAX;
            for (int j = 0; j < collect.size(); j++) {
                if (i == j)
                    continue;
                int k2 = (collect[i] - collect[j]) * (collect[i] - collect[j]);
                if (k2 == 0) {
                    minnum = 0;
                    break;
                }
                minnum = min(minnum, k2);
            }
            sum += minnum;
        }
        return sum;
    }
};

Node *tree[300010];

vector<int> DFS(Node *n) {
    n->collect.push_back(n->ax);
    for (Node *child: n->childs) {
        vector<int> t = DFS(child);
        for (int i = 0; i < t.size(); i++)
            n->collect.push_back(t[i]);
    }
    return n->collect;
}

int main() {

    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        tree[i] = new Node();
    }
    int p, a;
    for (int i = 2; i <= n; i++) {
        cin >> p;
        tree[p]->childs.push_back(tree[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a;
        tree[i]->ax = a;
    }


    DFS(tree[1]);
    for (int i = 1; i <= n; i++) {
        cout << tree[i]->Ans() << endl;
    }

}
