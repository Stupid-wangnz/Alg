#include <iostream>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;

class ComputeNode {
public:
    int areaNum;
    int id;
    vector<int> tasks;

    ComputeNode(int areaNum, int id) : areaNum(areaNum), id(id) {};
};

class nodeCompare {
public:
    bool operator()(const ComputeNode &n1, const ComputeNode &n2) {
        if (n1.tasks.size() != n2.tasks.size())
            return n1.tasks.size() < n2.tasks.size();
        return n1.id < n2.id;
    }
};


vector<ComputeNode> nodes;

void addna(int na, vector<ComputeNode> &waiting_nodes) {
    for (auto &node: nodes)
        if (node.areaNum == na)
            waiting_nodes.push_back(node);
}

void addpa(int pa, vector<ComputeNode> &waiting_nodes) {
    set<int> area;
    for (auto &node: waiting_nodes)
        if (find(node.tasks.begin(), node.tasks.end(), pa) != node.tasks.end())
            area.insert(node.areaNum);
    vector<ComputeNode> temp;
    for (auto &node: waiting_nodes)
        if (area.count(node.areaNum) != 0)
            temp.push_back(node);
    waiting_nodes = temp;
}

vector<ComputeNode> addpaa(int paa, vector<ComputeNode> waitingNode) {
    vector<ComputeNode> temp;
    for (auto &node: waitingNode)
        if (find(node.tasks.begin(), node.tasks.end(), paa) == node.tasks.end())
            temp.push_back(node);
    return temp;
}

int main() {
    int n, m;
    cin >> n >> m;
    nodes.push_back(ComputeNode(-1, -1));
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        ComputeNode cn(l, i + 1);
        nodes.push_back(cn);
    }

    int g;
    cin >> g;
    int f, a, na, pa, paa, paar;
    for (int i = 0; i < g; i++) {
        cin >> f >> a >> na >> pa >> paa >> paar;
        while (f--) {
            vector<ComputeNode> waiting_node;

            if (na)
                //节点亲和性
                addna(na, waiting_node);
            else
                waiting_node = nodes;

            if (pa) {
                //任务亲和性
                addpa(pa, waiting_node);
            }
            vector<ComputeNode> temppaa;
            if (paa) {
                temppaa = addpaa(paa, waiting_node);
            }

            if (temppaa.empty() && paar || waiting_node.empty()) {
                cout << 0 << " ";
                continue;
            }
            if (temppaa.empty() && !paar)
                temppaa = waiting_node;

            sort(temppaa.begin(), temppaa.end(), nodeCompare());
            ComputeNode fnode(-1, -1);
            for (auto & i : temppaa)
                if (i.id != -1) {
                    fnode = i;
                    break;
                }
            fnode.tasks.push_back(a);
            cout<<fnode.id<<" ";
            nodes[fnode.id] = fnode;
        }
        cout<<endl;
    }
}
