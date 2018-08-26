/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

 */

class Solution {
    int raw_search(int a[], int n, int v) {
        int l = 0, r = n - 1;
        while (l < r) {
            int t = (l + r) / 2;
            if (a[t] >= v) r = t;
            else l = t + 1;
        }
        if (a[l] == v) return l;
        return -1;
    }

public:
    int search(vector<int> &nums, int target) {
        if (nums.size() == 0) return -1;
        if (nums.size() > 1 && nums[nums.size() - 1] < nums[0]) {
            int l = 1, r = nums.size() - 1;
            while (l < r) {
                int t = (l + r) / 2;
                if (nums[t] < nums[0]) r = t;
                else l = t + 1;
            }
            if (target >= nums[0]) return raw_search(&nums[0], l, target);
            int ans = raw_search(&nums[l], nums.size() - l, target);
            if (ans == -1) return -1;
            return ans + l;
        } else return raw_search(&nums[0], nums.size(), target);
    }
};
