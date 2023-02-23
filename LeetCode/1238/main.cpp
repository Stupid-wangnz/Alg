#include <iostream>
#include <vector>

using namespace std;
//思路: 从最简单的n=0分析，开始为0，序列只能是[0]（格雷编码的思路：89）
//n=1: [0,1]， 无论将第n位bit进行翻转得到
//n=2: [0,1,3,2]，首先是得到[0,1],然后将其翻转拼接后得到[0,1,1,0]，对后面拼接上来的第n位进行翻转，得到[0,1,3 2]
//以此类推，就是从初始序列翻转拼接然后将拼接上来的后半段序列最高位翻转成为1
//start不确定时，先异或start，按照上述计算完了，再异或一次start
int main() {
    /*int n, start;
    cin >> n >> start;*/
    vector<int> p;
    p.reserve(1 << n);
    p.push_back(start);
    for (int i = 1; i <= n; i++) {
        int l = p.size();
        for (int j = l - 1; j >= 0; j--) {
            p.push_back(((p[j] ^ start) | (1 << (i - 1))) ^ start);
        }
    }
    /*for (int i: p)
        cout << i << " ";*/
    return p;
}
