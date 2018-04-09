/*

Implement regular expression matching with support for '.' and '*'.


'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

 */

#include <cstdio>
#include <string>

using namespace std;

class Solution {
public:
    bool tryMatch(const char s[], const char p[]) {
        // printf("s=%s, p=%s\n", s, p);
        if (s[0] == '\0' && p[0] == '\0') return true;
        if (p[0] == '\0') return false;
        bool ans = false;
        if (s[0] != '\0' && (p[0] == '.' || s[0] == p[0])) {
            if (p[1] != '*') ans = ans || tryMatch(s + 1, p + 1);
            else ans = ans || tryMatch(s + 1, p) || tryMatch(s + 1, p + 2);
        }
        if (p[1] == '*') ans = ans || tryMatch(s, p + 2);
        return ans;
    }

    bool isMatch(string s, string p) {
        return tryMatch(s.c_str(), p.c_str());
    }
};

/*
int main() {
    Solution x;
    printf("%d\n", x.isMatch("aa", ".*"));
    return 0;
}
 */
