#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cfloat>
#include<iomanip>
using namespace std;

class Node
{
public:
	double x;
	double y;
	Node() {}
	Node(double x, double y) :x(x), y(y)
	{}
};
vector<Node>nodes;

double Distance(Node n1,Node n2) {
	return (n1.x - n2.x) * (n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y);
}
Node* Closest_Pair_Rec(vector<Node>Px, vector<Node>Py) {
	//量度所有两点距离求出最邻近点对
	if (Px.size() <= 3)
	{
		int n1, n2;
		double min_len = DBL_MAX;
		for (int i = 0; i < Px.size()-1; i++)
		{
			for (int j = i + 1; j < Px.size(); j++) {
				double len = Distance(Px[i], Px[j]);
				if (len < min_len) {
					min_len = len;
					n1 = i;
					n2 = j;
				}
			}
		}
		Node* res_n = new Node[2]{ Px[n1],Px[n2] };
		return res_n;
	}


	vector<Node>Qx(Px.begin(), Px.begin() + Px.size() / 2);
	vector<Node>Qy(Py.begin(), Py.begin() + Py.size() / 2);

	vector<Node>Rx(Px.begin() + Px.size() / 2, Px.end());
	vector<Node>Ry(Py.begin() + Py.size() / 2, Py.end());

	Node* q = Closest_Pair_Rec(Qx, Qy);
	Node* r = Closest_Pair_Rec(Rx, Ry);

	double min_len = min(Distance(q[0], q[1]), Distance(r[0], r[1]));

	double x_maxInQ=Qx[Qx.size()-1].x;

	//S实际是按y排序的点集合
	vector<Node>S;
	for (int i = 0; i < Py.size(); i++)
	{
		if (abs(Py[i].x - x_maxInQ) < min_len)
			S.push_back(Py[i]);
	}

	double min_len_inS=DBL_MAX;
	int ns1, ns2;
	for (int i = 0; i < S.size(); i++) {
		for (int j = i + 1; j < min(i + 7, int(S.size())); j++) {
			double len = Distance(S[i], S[j]);
			if (len < min_len_inS) {
				min_len_inS = len;
				ns1 = i;
				ns2 = j;
			}
		}
	}

	if (min_len_inS < min_len)
		return new Node[2]{ S[ns1],S[ns2] };
	
	if (Distance(q[0], q[1])<Distance(r[0],r[1]))
		return new Node[2]{ q[0],q[1] };

	return new Node[2]{ r[0],r[1] };
}
void Closest_Pair(vector<Node>P) {
	vector<Node>X_nodes(P);
	vector<Node>Y_nodes(P);

	sort(X_nodes.begin(), X_nodes.end(), [&](const Node& a, const Node& b)->bool {return a.x < b.x; });
	sort(Y_nodes.begin(), Y_nodes.end(), [&](const Node& a, const Node& b)->bool {return a.y < b.y; });

	Node* n= Closest_Pair_Rec(X_nodes, Y_nodes);
	cout << fixed;
	cout.precision(2);
	cout << Distance(n[0], n[1]);
}



int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		Node n(x, y);
		nodes.push_back(n);
	}

	vector<Node>X_nodes(nodes);
	vector<Node>Y_nodes(nodes);

	sort(X_nodes.begin(), X_nodes.end(), [&](const Node& a, const Node& b)->bool {return a.x < b.x; });
	sort(Y_nodes.begin(), Y_nodes.end(), [&](const Node& a, const Node& b)->bool {return a.y < b.y; });

	Closest_Pair(nodes);
}