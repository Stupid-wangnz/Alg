#include<iostream>
using namespace std;
#include<vector>
int Iterative_Compute_Opt(int n, vector<int>V,vector<int>P)
{
	vector<int>M(n + 1, 0);
	for (int j = 1; j <= n; j++)
	{
		M[j] = max(V[j] + M[P[j]], M[j - 1]);
	}
	return M[n];
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

	cout << Iterative_Compute_Opt(n, v, p);

}