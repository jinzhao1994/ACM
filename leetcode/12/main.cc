/*

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

 */


class Solution {
private:
    // Tokens.
    const string t0[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    const string t1[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const string t2[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const string t3[10] = {"", "M", "MM", "MMM"};
public:
    string intToRoman(int num) {
        return t3[num / 1000 % 10] + t2[num / 100 % 10] + t1[num / 10 % 10] + t0[num % 10];
    }
};
