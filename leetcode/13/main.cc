/*

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

 */


class Solution {
private:
    // Values
    int v[128];
public:
    int romanToInt(string s) {
        v['I'] = 1;
        v['V'] = 5;
        v['X'] = 10;
        v['L'] = 50;
        v['C'] = 100;
        v['D'] = 500;
        v['M'] = 1000;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && v[s[i]] < v[s[i + 1]]) ans -= v[s[i]];
            else ans += v[s[i]];
        }
        return ans;
    }
};
