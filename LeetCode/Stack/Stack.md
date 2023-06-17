| 双指针 | Hard | 42. 接雨水 |
| ------ | ---- | ---------- |
|        |      |            |
|        |      |            |
|        |      |            |

## 42.接雨水

从前往后计算一次，从后往前计算一次

**O(m*n)**

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int h_max = 0, h_i = -1;
        stack<int> r_s;
        int n = height.size();
        int rain = 0;
        for(int i=0;i<n;i++){
            if(height[i] >= h_max){
                while(!r_s.empty()){
                    int h = r_s.top();
                    r_s.pop();
                    rain += (h_max - h);
                }
                h_max = height[i];
                h_i = i;
            }
            else{
                r_s.push(height[i]);
            }
        }
        stack<int>res_r_s;
        h_max = 0;
        for(int i=n-1;i>=h_i;i--){
            if(height[i] >= h_max){
                while(!res_r_s.empty()){
                    int h = res_r_s.top();
                    res_r_s.pop();
                    rain += (h_max - h);
                }
                h_max = height[i];
            }
            else{
                res_r_s.push(height[i]);
            }
        }

        return rain;
    }
};
```

**单调栈解法**O(N)

**意思就是，储存不了水的容器高度是单调下降的，如果出现上升，那么他们两个之间一定有空间可以存水**

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};

```

**双指针**O(N)

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1;
        int ans = 0;
        int l_max=height[0], r_max=height[n-1];
        while(l<r){
            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);
            if(l_max <= r_max){
                l++;
                if(height[l] < l_max)
                    ans += l_max - height[l];
            }
            else {
                r--;
                if(height[r] < r_max)
                    ans += r_max - height[r];
            }
        }
        return ans;
    }
};
```

