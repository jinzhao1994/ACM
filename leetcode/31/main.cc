/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 -> 1,3,2
3,2,1 -> 1,2,3
1,1,5 -> 1,5,1

 */

#include <algorithm>

using namespace std;

class Solution {
    void reverse(int *begin, int *end) {
        for (; begin < end; begin++, end--) swap(*begin, *end);
    }

public:
    void nextPermutation(vector<int> &nums) {
        int *a = &nums[0], n = nums.size();
        if (n <= 1) return;
        int i = n - 2, j = n - 1;
        while (i >= 0 && a[i] >= a[i + 1]) i--;
        if (i >= 0) {
            while (j > i && nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(a + i + 1, a + n - 1);
    }
};
