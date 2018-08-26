/*

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3

Example 2:

Input: dividend = 7, divisor = -3
Output: -2

Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [-2^31, 2^31-1].
For the purpose of this problem, assume that your function returns 2^31-1 when the division result overflows.

 */

const int MAX = ~0u >> 1;
const int MIN = -MAX - 1;

class Solution {
    unsigned int to_unsigned(int x) {
        if (x >= 0) return x;
        if (x == MIN) return (unsigned int) (MAX) + 1;
        return -x;
    }

    bool nag(int x) {
        return x < 0;
    }

    unsigned int cal(unsigned int a, unsigned int b) {
        unsigned int ans = 0;
        for (int i = __builtin_clz(b) - __builtin_clz(a); i >= 0; i--) {
            if (a >= (b << i)) {
                a -= b << i;
                ans += 1 << i;
            }
        }
        // printf("ans=%u mod=%u\n", ans, a);
        return ans;
    }

public:
    int divide(int dividend, int divisor) {
        if (dividend == MIN && divisor == -1) return MAX;
        unsigned int a = to_unsigned(dividend), b = to_unsigned(divisor);
        // printf("a=%u b=%u\n", a, b);
        if (nag(dividend) == nag(divisor)) return cal(a, b);
        else return -cal(a, b);
    }
};
