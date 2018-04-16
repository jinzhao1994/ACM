/*

Given an array nums of n integers and an integer target,
are there elements a, b, c, and d in nums such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

 */

#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector <vector<int>> fourSum(vector<int> &nums, int target) {
        vector <vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            for (int j = i + 1; j < nums.size();) {
                for (int l = j + 1, r = nums.size() - 1; l < r;) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        vector<int> tmp = {nums[i], nums[j], nums[l], nums[r]};
                        ans.emplace_back(tmp);
                        do l++; while (l < r && nums[l] == nums[l - 1]);
                        do r--; while (l < r && nums[r] == nums[r + 1]);
                    } else if (sum > target) {
                        do r--; while (l < r && nums[r] == nums[r + 1]);
                    } else if (sum < target) {
                        do l++; while (l < r && nums[l] == nums[l - 1]);
                    };
                }
                do j++; while (j < nums.size() && nums[j] == nums[j - 1]);
            }
            do i++; while (i < nums.size() && nums[i] == nums[i - 1]);
        }
        return ans;
    }
};
