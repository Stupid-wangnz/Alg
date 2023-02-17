#include <iostream>
#include <vector>

using namespace std;

//#define WINDOWS_X 2660
//#define WINDOWS_Y 1440
//int Windows[WINDOWS_X][WINDOWS_Y]{};

class win {
public:
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0, num = 0;

    void setWin(int x1, int y1, int x2, int y2, int num) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        this->num = num;
    }
};

vector<win> wins(10);
//win wins[10];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        win w;
        w.setWin(x1, y1, x2, y2, i);
        wins.push_back(w);
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        int j = wins.size() - 1;
        for (; j >= 0; j--) {
            if (x >= wins[j].x1 && x <= wins[j].x2 && y <= wins[j].y2 && y >= wins[j].y1) {
                cout <<wins[j].num<<endl;
                wins.push_back(wins[j]);
                wins.erase(wins.begin()+j);
                break;
            }
        }
        if(j<0)
            cout<<"IGNORED"<<endl;

    }
}
