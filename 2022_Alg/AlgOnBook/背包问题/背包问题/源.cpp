#include<iostream>
using namespace std;

int n, W;
int* w;
int* v;
void Bag_Solutions(int n,int W)
{
	int** M = new int* [n+1];
	for (int i = 0; i <=n; i++)
		M[i] = new int[W+1];

	for (int i = 0; i <= W; i++)
		M[0][i] = 0;

	for(int i=1;i<=n;i++)
		for (int j = 1; j <= W; j++) {
			M[i][j] = max(M[i - 1][j], v[i] + M[i - 1][j - w[i]]);
		}

	cout << M[n][W];
}

int main()
{
	cin >> n >> W;
	w = new int[n+1];
	v = new int[n+1];
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	Bag_Solutions(n, W);
}