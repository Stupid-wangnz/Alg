#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
n个蝴蝶
m个判断
用一个O（m+n）算法判断这个m个判断是否一致
*/
int n, m;
int relation[1000][1000];
int color[1000];
bool visit_list[1000];
queue<int>bfs_queue;

bool Bfs()
{
	while (!bfs_queue.empty()) {
		int v = bfs_queue.front();
		bfs_queue.pop();
		for (int i = 0; i < n; i++) {
			if (relation[v][i] == -1)
				continue;
			if (visit_list[i]) {
				if ((relation[v][i] == 0 && color[v] == color[i]) || (relation[v][i] == 1 && color[v] != color[i]))
					continue;
				else 
					return false;
			}
			else
			{
				visit_list[i] = 1;
				if (relation[v][i] == 0)
					color[i] = color[v];
				if (relation[v][i] == 1)
					color[i] = -color[v];

				bfs_queue.push(i);
			}
		}
	}
	return true;
}

int main()
{
	cin >> n >> m;
	
	memset(color, 0, sizeof(color));
	memset(visit_list, 0, sizeof(visit_list));
	memset(relation, -1, sizeof(relation));

	for (int i = 0; i < m; i++)
	{
		int s, v, r;
		cin >> s >> v >> r;
		relation[s][v] = r;
	}

	for (int i = 0; i < n; i++)
	{
		if (visit_list[i])
			continue;
		visit_list[i] = 1;
		color[i] = 1;
		bfs_queue.push(i);
		if (!Bfs()) {
			cout << "err";
			return 0;
		}
	}
	cout << "yes";
}