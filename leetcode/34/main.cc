/*

Given an array of integers nums sorted in ascending order,
find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

 */

class Solution {
    int lower_bound(int a[], int n, int v) {
        int l = 0, r = n - 1;
        while (l < r) {
            int t = (l + r) / 2;
            if (a[t] >= v) r = t;
            else l = t + 1;
        }
        if (a[l] == v) return l;
        else return -1;
    }

    int upper_bound(int a[], int n, int v) {
        int l = 0, r = n - 1;
        while (l < r) {
            int t = (l + r) / 2;
            if (a[t + 1] <= v) l = t + 1;
            else r = t;
        }
        if (a[l] == v) return l;
        else return -1;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.size() == 0) return vector<int> {-1, -1};
        vector<int> ans;
        ans.push_back(lower_bound(&nums[0], nums.size(), target));
        ans.push_back(upper_bound(&nums[0], nums.size(), target));
        return ans;
    }
};
