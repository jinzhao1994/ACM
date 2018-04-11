/*

Write a function to find the longest common prefix string amongst an array of strings.

 */

class Solution {
public:
    string longestCommonPrefix(vector <string> &strs) {
        if (strs.size() == 0) return "";
        for (int j = 0; j < strs[0].length(); j++) {
            for (int i = 1; i < strs.size(); i++) {
                if (j >= strs[i].length() || strs[i][j] != strs[0][j]) {
                    return strs[0].substr(0, j);
                }
            }
        }
        return strs[0];
    }
};
