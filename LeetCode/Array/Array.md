| 双指针     | Medium        | [11. 盛最多水的容器](11盛最多水的容器\11.md)                 |
| ---------- | ------------- | ------------------------------------------------------------ |
|            |               | 15.三数之和                                                  |
|            |               | 16.最接近的三数之和                                          |
|            | Easy          | 27.移除元素                                                  |
| **二分法** | **difficult** | [4.寻找两个正序数组的中位数.md](4寻找两个正序数组的中位数\4.md) |
|            |               |                                                              |
|            | medium        | [33. 搜索旋转排序数组](https://leetcode.cn/problems/search-in-rotated-sorted-array/) |
|            | medium        | [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/) |



## 15.三数之和

**双指针+排序去重**

```三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>n-3)
                break;
            if(i!=0 && nums[i] == nums[i-1])
                continue;
            int L = i+1, R = n-1;
            int numi = nums[i];
            while(L<R){
                int sum = nums[L]+nums[R]+numi;
                if(sum == 0){
                    vector<int> res = {numi, nums[L], nums[R]};
                    ans.push_back(res);
                    do L++; while(nums[L] == nums[L-1] && L!=n-1);
                    do R--; while(nums[R] == nums[R+1] && R!=0);
                }
                if(sum < 0)
                    do L++; while(nums[L] == nums[L-1] && L!=n-1);
                if(sum > 0)
                    do R--; while(nums[R] == nums[R+1] && R!=0);
            }
        }
        return ans;
    }
};
```

## 16.最接近的三数之和

与**15**类似

```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_d = INT_MAX;
        int min_d_sum = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            int L = i+1, R=n-1, sum;
            while(L<R){
                sum = nums[i] + nums[L] + nums[R];
                if(abs(sum - target) < min_d){
                    min_d = abs(sum - target);
                    min_d_sum = sum;
                }
                if(sum-target == 0)
                    return target;
                else if(sum > target)
                    R--;
                else if(sum < target)
                    L++;
            }
        }
        return min_d_sum;
    }
};
```

## 18.两数之和

跟前面一样的思路，需要注意的是智障的long long问题。

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-3;i++){
            if(i!=0 && nums[i] == nums[i-1])
                continue;        
            for(int j=i+1;j<n-2;j++){
                if(j!=i+1 && nums[j] == nums[j-1])
                    continue;
                long long sum = nums[i] + nums[j];
                int L = j+1, R = n-1;
                while(L<R){
                    long long sum_t = sum + nums[L] + nums[R];
                    if(sum_t == target){
                        vector<int> res = {nums[i], nums[j], nums[L], nums[R]};
                        ans.push_back(res);
                        do L++; while(nums[L]==nums[L-1] && L!=n-1);
                        do R--; while(nums[R]==nums[R+1] && R!=0);
                    }
                    if(sum_t > target)
                        do R--; while(nums[R]==nums[R+1] && R!=0);
                    else if(sum_t < target)
                        do L++; while(nums[L]==nums[L-1] && L!=n-1);
                }
            }
        }
        return ans;
    }
};
```

## 26.Remove Duplicates from Sorted Array

简单的O(n)，注意数组边界问题

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i=0;i<n;){
            nums[k] = nums[i];
            k++;
            do i++; while(i != n && nums[i] == nums[i-1]);
        }
        return k;
    }
};
```

## 27.移除元素

一个指针指向前面都是不含val的数，一个指针指向数组后面全是val的值

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int s = 0, e = nums.size()-1;
        if(e == -1)
            return 0;
        while(e>=0 && nums[e]==val){
            e--;
        }
        while(s<=e){
            if(nums[s] == val){
                nums[s] = nums[e];
                nums[e] = val;
                while(e>=0 && nums[e]==val)
                    e--;
            }
            s++;
        }
        return s;
    }
};
```



## 33. 搜索旋转排序数组

先找到target在的那一段有序数组

```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n==0) 
            return -1;

        if (n == 1) 
            return nums[0] == target ? 0 : -1;
    
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid =(l+r)/2;
            if (nums[mid] == target) 
                return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
```

## 34. 在排序数组中查找元素的第一个和最后一个位置

其实就是简单的二分搜索，当遍历到target的时候别停，根据当前在找左边界还是右边界来更新，继续搜索。

```
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool left){
        int l=0, r=nums.size()-1;
        int res=-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                res = mid;
                if(left)
                    r = mid-1;
                else
                    l = mid+1;
            }
            if(nums[mid]<target)
                l=mid+1;
            if(nums[mid]>target)
                r=mid-1;
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, target, true), binarySearch(nums, target, false)};
    }
};
```

