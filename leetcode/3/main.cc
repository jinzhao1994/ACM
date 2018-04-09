/*

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

 */

#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, current = 0;
        int last[256];
        for (int i = 0; i < 256; i++) last[i] = -1;
        for (int i = 0; i < s.length(); i++) {
            current = min(current + 1, i - last[s[i]]);
            ans = max(ans, current);
            last[s[i]] = i;
        }
        return ans;
    }
};
