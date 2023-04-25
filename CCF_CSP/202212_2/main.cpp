#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int proj_ref[105];
int proj_time[105];

int cal_pre(int i) {
    int head = 0;
    if (proj_ref[i]) {
        head += cal_pre(proj_ref[i]) + proj_time[proj_ref[i]];
    }
    return head;
}

int n1, m;

class Node {
public:
    vector<Node *> childs;
    int train;
    int last;

    Node(int t = 0) {
        train = t;
        last = INT_MAX;
    };
};

int totalTime = 0;
int train = 0;

void DFS(Node *n) {
    train += n->train;
    if (n->childs.empty()) {
        n->last = n1 - n->train + 1;
        totalTime = max(totalTime, train);
        train -= n->train;
        return;
    }
    for (int i = 0; i < n->childs.size(); i++) {
        DFS(n->childs[i]);
        n->last = min(n->last, n->childs[i]->last - n->train);
    }
    train -= n->train;
    return;
}

int main() {
    cin >> n1 >> m;
    for (int i = 1; i <= m; i++)
        cin >> proj_ref[i];
    for (int i = 1; i <= m; i++)
        cin >> proj_time[i];

    for (int i = 1; i <= m; i++) {
        cout << cal_pre(i) + 1 << " ";
    }
    cout << endl;

    Node *tree[105];
    for (int i = 0; i <= m; i++)
        tree[i] = new Node();

    for (int i = 1; i <= m; i++) {
        tree[proj_ref[i]]->childs.push_back(tree[i]);
        tree[i]->train = proj_time[i];
    }
    DFS(tree[0]);
    //cout << totalTime;

    if (totalTime > n1)
        return 0;
    for (int i = 1; i <= m; i++) {
        cout << tree[i]->last << " ";
    }

}
