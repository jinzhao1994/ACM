/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R


And then read line by line: "PAHNAPLSIIGYIR"


Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

 */

#include <sstream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ans;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; true; j += 2 * numRows - 2) {
                if (j + i >= s.length()) break;
                ans.push_back(s[j + i]);
                if (i == 0 || i == numRows - 1) continue;
                if (j + 2 * numRows - 2 - i >= s.length()) break;
                ans.push_back(s[j + 2 * numRows - 2 - i]);
            }
        }
        return ans;
    }
};
