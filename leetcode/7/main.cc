/*

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321


Example 2:

Input: -123
Output: -321


Example 3:

Input: 120
Output: 21


Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range.
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

 */

#include <iostream>

using namespace std;

// const int INT_MAX = ~0u >> 1;
// const int INT_MIN = INT_MAX + 1;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            if (ans > (INT_MAX / 10) + (INT_MAX % 10 - x % 10) / 10) return 0;
            if (ans < (INT_MIN / 10) + (INT_MIN % 10 + x % 10) / 10) return 0;
            // cout << "--- " << x % 10 << endl;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};

/*
int main() {
    Solution x;
    cout << x.reverse(-123) << endl;
    return 0;
}
 */
