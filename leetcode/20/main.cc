/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true

 */

#include <stack>

using namespace std;

class Solution {
private:
    bool isPair(char x, char y) {
        return (x == '(' && y == ')') || (x == '[' && y == ']') || (x == '{' && y == '}');
    }

public:
    bool isValid(string s) {
        stack<char> d;
        for (int i = 0; i < s.size(); i++) {
            if (d.size() > 0 && isPair(d.top(), s[i])) {
                d.pop();
            } else {
                d.push(s[i]);
            }
        }
        return d.size() == 0;
    }
};
