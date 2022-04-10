#include<iostream>
using namespace std;
#include<queue>
#include<iomanip>

class Node {
public:
	Node* l_child;
	Node* r_child;

	int count;

	Node(Node*l,Node*r) {
		l_child = l;
		r_child = r;
		count = 0;

		if (l != NULL)
			count = l_child->count + r_child->count;
	}

	Node(int c) {
		l_child = NULL;
		r_child = NULL;
		count = c;
	}

	bool hasNext() {
		return l_child != NULL;
	}
};
struct cmp {
	bool operator ()(Node *a1, Node *a2) {
		return a1->count > a2->count;
	}
};

void DFS(int& len, Node* root, int deep = 0) {
	if (root->hasNext()) {
		DFS(len, root->l_child, deep + 1);
		DFS(len, root->r_child, deep + 1);

	}
	else {
		len += deep * root->count;
	}
}

int main()
{
	int N;
	cin >> N;
	priority_queue<Node*, vector<Node*>, cmp>priority_queue;
	for (int i = 0; i < N; i++)
	{
		int count;
		cin >> count;
		Node* n = new Node(count);
		priority_queue.push(n);
	}

	while (priority_queue.size() > 1) {
		Node *l = priority_queue.top();
		priority_queue.pop();
		Node *r = priority_queue.top();
		priority_queue.pop();
		Node *new_Node = new Node(l, r);
		priority_queue.push(new_Node);
	}

	Node *root = priority_queue.top();
	int sum_count = root->count;
	int sum_len = 0;

	DFS(sum_len, root);
	cout << fixed;
	cout.precision(2);
	cout<< (float)sum_len / sum_count;
}