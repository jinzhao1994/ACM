/*

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.


For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

 */

#include <algorithm>

using namespace std;

class Solution {
public:
    vector <vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector <vector<int>> ans;
        for (int i = 0; i < nums.size();) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    ans.push_back(tmp);
                }
                if (nums[i] + nums[j] + nums[k] >= 0) {
                    do k--; while (j < k && nums[k] == nums[k + 1]);
                } else {
                    do j++; while (j < k && nums[j] == nums[j - 1]);
                }
            }
            do i++; while (i < nums.size() && nums[i] == nums[i - 1]);
        }
        return ans;
    }
};
