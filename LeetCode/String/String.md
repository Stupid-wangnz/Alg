# String

| 滑动窗口 | Medium | 3.                    |
| -------- | ------ | --------------------- |
|          |        |                       |
| KMP算法  | Medium | 28.找出第一个子串下标 |
|          |        |                       |

## 3.无重复字符的最长子串

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int n = s.size();
        int record[256] = {};
        int i_end = 1;
        for(int i=0;i<n;i++){
            max_len = max(max_len, 1);
            i_end = max(i_end, i+1);
            record[s[i]] = 1;
            while(i_end < n){
                if(record[s[i_end]] == 0){
                    record[s[i_end]] = 1;
                    max_len = max(max_len, i_end - i + 1);
                }
                else
                    break;
                i_end++;
            }
            if(i_end == n)
                break;
            record[s[i]] = 0;
        }
        return max_len;
    }
};
```

## 6.N字形变换

```c++
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string ans = "";
        int z_len = 2*numRows - 2;
        for(int row=0;row<numRows;row++){
            int skip = z_len - 2*row;
            skip = z_len - skip;
            if(skip==0)
                skip = z_len;
            for(int i=row;i<s.size();i+=skip){
                ans += s[i];
                skip = z_len - skip;
                if(skip==0)
                    skip = z_len;
            }
        }
        return ans;
    }
};
```

## 28.找出字符串中第一个匹配项的下标

暴力解法O(mn):

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int needle_len = needle.size();
        int n = haystack.size();
        for(int i=0;i<n-needle_len+1;i++){
            bool flag = true;
            for(int j=i;j<needle_len+i;j++){
                if(needle[j-i] != haystack[j]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return i;
        }
        return -1;
    }
};
```

KMP O(m+n):

**没看懂**

```
class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        if(m == 0) return 0;
        //设置哨兵
        s.insert(s.begin(),' ');
        p.insert(p.begin(),' ');
        vector<int> next(m + 1);
        //预处理next数组
        for(int i = 2, j = 0; i <= m; i++){
            while(j and p[i] != p[j + 1]) j = next[j];
            if(p[i] == p[j + 1]) j++;
            next[i] = j;
        }
        //匹配过程
        for(int i = 1, j = 0; i <= n; i++){
            while(j and s[i] != p[j + 1]) j = next[j];
            if(s[i] == p[j + 1]) j++;
            if(j == m) return i - m;
        }
        return -1;
    }
};
```

