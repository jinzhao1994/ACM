/*

Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

 */

#include <cstdio>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        if (x % 10 == 0) return false;
        int y = 0;
        while (x >= y) {
            // printf("%d %d\n", x, y);
            if (x == y) return true;
            if (y == x / 10) return true;
            y = y * 10 + x % 10;
            x /= 10;
        }
        return false;
    }
};

/*
int main() {
    Solution x;
    printf("%d\n", x.isPalindrome(123));
    return 0;
}
 */
