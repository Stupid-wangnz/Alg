#### Medium[22. 括号生成](https://leetcode.cn/problems/generate-parentheses/)

```
class Solution {
public:
    string cur = "";
    vector<string> ans;
    void generateAll(int l, int r, int n){
        if(cur.length() == 2*n){
            ans.push_back(cur);
            return;
        }
        if(l < n){
            cur += "(";
            generateAll(l+1, r, n);
            cur.pop_back();
        }
        if(r < l){
            cur += ")";
            generateAll(l, r+1, n);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        generateAll(0, 0, n);
        return ans;
    }
};
```



#### Hard[32. 最长有效括号](https://leetcode.cn/problems/longest-valid-parentheses/)

一个巧妙的将括号匹配转化到动态规划的题目，首先我们现在要求一个长度为n的字符串中的最长子串，使用一个dp数组来记录，dp[i]表示从0到i的这个子串必须以i为结尾的最长有效括号的长度。

1. 当s[i] =')', s[i-1] == '('，目前的字符串是一个'...()'的形式，所以dp[i] = dp[i-2] + 2.
2. 当s[i] =')', s[i-1] == ')'，目前的字符串是一个'...))'的形式，此时如果dp[i-1]不为0，即i-dp[i-1]到i-1这个是有效子串，且s[i-dp[i]-1]='('，那么构成了'(sub_str)'这种格式，所以dp[i] = dp[i-1] + 2。但是此时需要注意，可能前面也有一个子串，即's1(s2)'这种格式，现在的dp[i]只计算了(s2)这段长度，还需要加上s1的长度

```
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n == 0)
            return n;
        int len = 0;
        vector<int> dp(n, 0);
        for(int i=1;i<n;i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    if(i == 1)
                        dp[i] = 2;
                    else{
                        dp[i] = dp[i-2] + 2;
                    }
                }
                else if(s[i-1] == ')' && i-dp[i-1]-1>=0 && s[i - dp[i-1] -1]=='('){
                    dp[i] = dp[i-1] + 2;
                    if(dp[i]<=i)
                        dp[i] += dp[i-dp[i]];
                }
            }
            len = max(len, dp[i]);
        }
        return len;
    }
};
```

