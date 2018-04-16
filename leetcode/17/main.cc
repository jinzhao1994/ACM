/*

Given a string containing digits from 2-9 inclusive,
return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

 */

class Solution {
private:
    const char *s[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector <string> letterCombinations(string digits) {
        vector <string> ans, tmp;
        if (digits == "") {
            return ans;
        }
        ans.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            tmp.clear();
            for (int j = 0; j < ans.size(); j++) {
                for (int k = 0; s[digits[i] - '0'][k] != '\0'; k++) {
                    tmp.emplace_back(ans[j] + s[digits[i] - '0'][k]);
                }
            }
            swap(ans, tmp);
        }
        return ans;
    }
};
