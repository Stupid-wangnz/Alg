#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        dp[len1][len2] = 0;
        for (int i = 0; i < len1; i++)
            dp[i][len2] = len1 - i;
        for (int j = 0; j < len2; j++)
            dp[len1][j] = len2 - j;
        for (int i = len1 - 1; i >= 0; i--)
            for (int j = len2 - 1; j >= 0; j--) {
                if (str1[i] == str2[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
            }

        string res = "";
        int p1 = 0, p2 = 0;
        while (p1 != len1 && p2 != len2) {
            if (str1[p1] == str2[p2]) {
                res += str1[p1];
                p1++;
                p2++;
            } else {
                if (dp[p1][p2] == dp[p1 + 1][p2] + 1){
                    res += str1[p1];
                    p1++;
                }else if(dp[p1][p2] == dp[p1][p2 + 1] + 1){
                    res += str2[p2];
                    p2++;
                }
            }
        }

        while(p1!=len1){
            res += str1[p1];
            p1++;
        }
        while(p2!=len2){
            res += str2[p2];
            p2++;
        }

        return res;
    }
};

int main() {

}
