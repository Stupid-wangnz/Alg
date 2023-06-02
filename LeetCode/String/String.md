# String

| 滑动窗口 | Medium | 3.   |
| -------- | ------ | ---- |
|          |        |      |
|          |        |      |
|          |        |      |

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

