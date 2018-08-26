/*

Given a string containing just the characters '(' and ')',
find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"


Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

 */

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> a(s.size(), -1);
        stack<int> c;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') c.push(i);
            else if (c.size() > 0) {
                int j = c.top();
                c.pop();
                a[j] = i;
            }
        }
        int ans = 0, cur = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' && a[i] != -1) {
                cur += a[i] - i + 1;
                i = a[i];
                ans = max(ans, cur);
            } else cur = 0;
        }
        return ans;
    }
};
