/*

You are given a string, s, and a list of words, words, that are all of the same length.
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
Output: []

 */

#include <unordered_map>

class Solution {
public:
    vector<int> findSubstring(string s, vector <string> &words) {
        vector<int> ans;
        if (words.size() == 0) return ans;
        int m = words[0].size();
        unordered_map<string, int> need, have;
        for (int i = 0; i < words.size(); i++) need[words[i]]++;
        for (int i = 0; i < m; i++) {
            have.clear();
            int have_count = 0;
            for (int j = i; j < s.size(); j+=m) {
                int left = j - m * (words.size() - 1);
                // printf("j=%d, left=%d\n", j, left);
                string tmp = s.substr(j, m);
                // printf("  +%s\n", tmp.c_str());
                if (need.find(tmp) != need.end()) {
                    have[tmp]++;
                    if (have[tmp] <= need[tmp]) have_count++;
                }
                // for (const auto & it : have) printf("-- %s %d\n", it.first.c_str(), it.second);
                if (left < 0) continue;
                if (have_count == words.size()) ans.push_back(left);
                tmp = s.substr(left, m);
                // printf("  -%s\n", tmp.c_str());
                if (need.find(tmp) != need.end()) {
                    have[tmp]--;
                    if (have[tmp] < need[tmp]) have_count--;
                }
            }
        }
        return ans;
    }
};
