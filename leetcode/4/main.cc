/*

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0



Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

 */

#include <algorithm>

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findK(vector<int> &nums1, vector<int> &nums2, int k) {
        int l1 = 0, r1 = nums1.size(), l2 = 0, r2 = nums2.size();
        while (l1 != r1 && l2 != r2) {
            int m1 = (l1 + r1) / 2, m2 = (l2 + r2) / 2;
            if (nums1[m1] >= nums2[m2]) {
                if (m1 + m2 >= k) r1 = m1;
                else l2 = m2 + 1;
            } else {
                if (m1 + m2 >= k) r2 = m2;
                else l1 = m1 + 1;
            }
        }
        if (l1 == r1) l2 = k - l1;
        else l1 = k - l2;
        // printf("-- k=%d l1=%d l2=%d\n", k, l1, l2);
        if (l1 == nums1.size()) return nums2[l2];
        if (l2 == nums2.size()) return nums1[l1];
        return min(nums1[l1], nums2[l2]);
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 1) {
            return findK(nums1, nums2, total / 2);
        } else {
            return ((double) findK(nums1, nums2, total / 2) + findK(nums1, nums2, total / 2 - 1)) / 2;
        }
    }
};

/*
int main() {
    Solution x;
    vector<int> a = {2};
    vector<int> b = {};
    printf("%.5f\n", x.findMedianSortedArrays(a, b));
}
 */
