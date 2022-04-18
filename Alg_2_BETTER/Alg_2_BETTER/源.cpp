#include<iostream>
#include<queue>
#include<vector>
#include<iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum_times = 0;
	double sum_len = 0;
	priority_queue<int, vector<int>, greater<int>>SourceQUEUE;

	for (int i = 0; i < n; i++) {
		int cur_times;
		cin >> cur_times;
		SourceQUEUE.push(cur_times);
		sum_times += cur_times;
	}
	int l_times, r_times,new_times;
	while (SourceQUEUE.size() >= 2) {
		l_times = SourceQUEUE.top();
		SourceQUEUE.pop();
		r_times = SourceQUEUE.top();
		SourceQUEUE.pop();

		new_times = l_times + r_times;
		sum_len += new_times;
		SourceQUEUE.push(new_times);
	}

	cout << fixed;
	cout.precision(2);
	cout<< sum_len / sum_times;
}