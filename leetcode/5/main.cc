/*

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.


Example:

Input: "cbbd"

Output: "bb"

 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for (int i = 0; i < s.length(); i++) {
            int k = 0;
            while (i - k >= 0 && i + k < s.length() && s[i - k] == s[i + k]) k++;
            // cout << "== i=" << i << " k=" << k << endl;
            if (k * 2 - 1 > ans.length()) ans = s.substr(i - k + 1, k * 2 - 1);
            k = 0;
            while (i - k - 1 >= 0 && i + k < s.length() && s[i - k - 1] == s[i + k]) k++;
            // cout << "== i=" << i << " k=" << k << endl;
            if (k * 2 > ans.length()) ans = s.substr(i - k, k * 2);
        }
        return ans;
    }
};

/*
int main() {
    Solution x;
    cout << x.longestPalindrome("cbbd") << endl;
    return 0;
}
 */
