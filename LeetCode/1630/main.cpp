#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkSubarray(vector<int> &nums, int l, int r) {
        //O(l*logl)
        /*
        vector<int> t(nums.begin() + l, nums.begin() + r + 1);
        sort(t.begin(), t.end());
        int dif = t[1] - t[0];
        for (int i = 2; i <= r - l; i++) {
            if (t[i] - t[i - 1] != dif)
                return false;
        }
        return true;*/

        //O(l):
        int max = INT_MIN, min = INT_MAX;
        for (int i = l; i <= r; i++) {
            if (nums[i] > max)
                max = nums[i];
            if (nums[i] < min)
                min = nums[i];
        }
        if (max == min)
            return true;

        int d = (max - min) / (r - l);
        if (d * (r - l) != max - min)
            return false;

        vector<bool> ss(r - l + 1, false);
        for (int i = l; i <= r; i++) {
            int t = (nums[i] - min) / d;
            if (t * d + min != nums[i])
                return false;
            ss[t] = true;
        }
        for (int i = 0; i <= r - l; i++) {
            if (!ss[i])
                return false;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
        vector<bool> res;
        int m = l.size();
        for (int i = 0; i < m; i++) {
            res.push_back(checkSubarray(nums, l[i], r[i]));
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
