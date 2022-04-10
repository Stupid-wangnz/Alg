#include<iostream>
using namespace std;

bool IsFull(int* current,int n) {
	for (int i = 0; i < n; i++)
		if (current[i] == -1)
			return 0;
	return 1;
}

int main() {
	int n;
	cin >> n;

	int** Perf_Man = new int* [n];
	for (int i = 0; i < n; i++)
		Perf_Man[i] = new int[n];

	int** Perf_Woman = new int* [n];
	for (int i = 0; i < n; i++)
		Perf_Woman[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> Perf_Man[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> Perf_Woman[i][j];
	
	int** Res_Perf_Woman = new int* [n];
	for (int i = 0; i < n; i++)
		Res_Perf_Woman[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			Res_Perf_Woman[i][Perf_Woman[i][j]-1] = j;

	int* next = new int[n];
	for (int i = 0; i < n; i++)
		next[i] = 0;

	int* current = new int[n];
	for (int i = 0; i < n; i++)
		current[i] = -1;
	int* isDate = new int[n];
	for (int i = 0; i < n; i++)
		isDate[i] = 0;
	while (!IsFull(current, n)) {
		for (int i = 0; i < n; i++) {
			if (!isDate[i]) {
				if (current[Perf_Man[i][next[i]] - 1] == -1)
				{
					current[Perf_Man[i][next[i]] - 1] = i;
					isDate[i] = 1;
				}
				else {
					int manNum = current[Perf_Man[i][next[i]] - 1];
					int womanNum = Perf_Man[i][next[i]] - 1;

					if (Res_Perf_Woman[womanNum][i] < Res_Perf_Woman[womanNum][manNum])
					{
						isDate[i] = 1;
						isDate[manNum] = 0;
						current[womanNum] = i;

					
					}
				}
				next[i]++;
			}

		}
	}

	int* res = new int[n];
	for (int i = 0; i < n; i++)
		res[current[i]] = i+1;

	for (int i = 0; i < n; i++)
	{
		cout << res[i];
		if (i < n - 1)
			cout << " ";
	}
}