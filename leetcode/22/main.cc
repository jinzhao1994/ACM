/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

 */

class Solution {
public:
    void dfs(int l, int r, int i, char s[], vector <string> &ans) {
        if (l == 0 && r == 0) {
            s[i] = '\0';
            ans.push_back(s);
            return;
        }
        if (l > 0) {
            s[i] = '(';
            dfs(l - 1, r + 1, i + 1, s, ans);
        }
        if (r > 0) {
            s[i] = ')';
            dfs(l, r - 1, i + 1, s, ans);
        }
    }

    vector <string> generateParenthesis(int n) {
        vector <string> ans;
        char *s = new char[n * 2 + 1];
        dfs(n, 0, 0, s, ans);
        delete[] s;
        return ans;
    }
};
