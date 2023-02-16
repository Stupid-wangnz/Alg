#include <iostream>
#include <cstring>

using namespace std;

#define MAXR 50
#define MAXC 50
char Map[MAXR][MAXC];
bool Mark1[MAXR][MAXC];
bool Mark2[MAXR][MAXC];

int R, C;

void DFS(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C)
        return;
    if (Mark1[x][y])
        return;
    if (Map[x][y] == '#')
        return;
    Mark1[x][y] = true;
    if (Map[x][y] == 'S' || Map[x][y] == '+' || Map[x][y] == 'T') {
        DFS(x, y + 1);
        DFS(x, y - 1);
        DFS(x + 1, y);
        DFS(x - 1, y);
    } else if (Map[x][y] == '-') {
        DFS(x, y - 1);
        DFS(x, y + 1);
    } else if (Map[x][y] == '|') {
        DFS(x + 1, y);
        DFS(x - 1, y);
    } else if (Map[x][y] == '.') {
        DFS(x + 1, y);
    }
}

void reverse_DFS(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C)
        return;
    if (Mark2[x][y])
        return;
    if (Map[x][y] == '#')
        return;
    Mark2[x][y] = true;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++) {
        int x1 = x + dx[i], y1 = y + dy[i];
        if (Map[x1][y1] == 'S' || Map[x1][y1] == 'T' || Map[x1][y1] == '+')
            reverse_DFS(x1, y1);
        else if (Map[x1][y1] == '|' && i >=2 )
            reverse_DFS(x1, y1);
        else if (Map[x1][y1] == '-' && i <= 1)
            reverse_DFS(x1, y1);
        else if (Map[x1][y1] == '.' && i == 3)
            reverse_DFS(x1, y1);
    }
}

int main() {
    memset(Mark1, 0, sizeof(Mark1));
    memset(Mark2, 0, sizeof(Mark2));

    cin >> R >> C;
    int start_x, start_y, t_x, t_y;
    for (int i = 0; i < R; i++){
        string mapstr;
        cin>>mapstr;
        for (int j = 0; j < C; j++) {
           Map[i][j] = mapstr[j];
            if (Map[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
            if (Map[i][j] == 'T') {
                t_x = i;
                t_y = j;
            }
        }
    }
    DFS(start_x, start_y);
    if(!Mark1[t_x][t_y]){
        cout<<"I'm stuck!";
        return 0;
    }
    reverse_DFS(t_x,t_y);
    int count=0;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++){
            if(Mark1[i][j]&&!Mark2[i][j]){
                count++;
            }
        }
    cout<<count;
    return 0;
}
