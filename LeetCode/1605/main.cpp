#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        int t = -1;
        vector<vector<int>> res(n, vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                t = min(rowSum[i],colSum[j]);
                res[i][j] = t;
                rowSum[i] -= t;
                colSum[j] -= t;
            }

        return res;
    }
};



int main() {
    vector<int> r = {3,8} , c = {4,7};
    vector<vector<int>> res = Solution().restoreMatrix(r,c);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
}
