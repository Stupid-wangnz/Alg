#include<iostream>
using namespace std;
#include<vector>

//递归
int Compute_Opt(int j,int n, vector<int>V, vector<int>P)
{

	if (j == 0)
		return 0;

	return max(V[j] + Compute_Opt(P[j], n, V, P), Compute_Opt(j - 1, n, V, P));
}

int M_Compute_Opt(int j, int n, vector<int>V, vector<int>P,vector<int>M)
{
	if (j == 0)
		return 0;
	if (M[j] != -1)
		return M[j];

	M[j]=max(V[j] + M_Compute_Opt(P[j], n, V, P,M), M_Compute_Opt(j - 1, n, V, P,M));
	return M[j];
}

//迭代
vector<int> Iterative_Compute_Opt(int n, vector<int>V,vector<int>P)
{
	vector<int>M(n + 1, 0);
	for (int j = 1; j <= n; j++)
	{
		M[j] = max(V[j] + M[P[j]], M[j - 1]);
	}
	return M;
}
void main() {

	int n;
	cin >> n;

	vector<int>s(n + 1, 0);
	vector<int>f(n + 1, 0);
	vector<int>v(n + 1, 0);

	for (int i = 1; i <= n; i++)
		cin >> s[i] >> f[i] >> v[i];
	//已经排序好了

	vector<int>p(n + 1, 0);
	for (int i = n; i >= 1; i--)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			if (f[j] <= s[i]) {
				p[i] = j;
				break;
			}
		}
	}
	cout << Compute_Opt(n, n, v, p);

	vector<int>m(n + 1, -1);

	cout << M_Compute_Opt(n, n, v, p, m);

	cout<<Iterative_Compute_Opt(n, v, p)[n];

}