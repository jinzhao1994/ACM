// BEGIN CUT HERE
// PROBLEM STATEMENT
// Correct parentheses sequences can be defined recursively as follows:
// 
// The empty string "" is a correct sequence.
// If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
// If "X" is a correct sequence, then "(X)" is a correct sequence.
// Each correct parentheses sequence can be derived using the above rules.
// 
// Examples of correct parentheses sequences include "", "()", "()()()", "(()())", and "(((())))".
// 
// 
// We can define the depth of a correct parentheses sequence recursively as follows:
// 
// 
// The empty string "" has depth 0.
// If the depth of "X" is x and the depth of "Y" is y then the depth of "XY" is max(x,y).
// If the depth of "X" is x then the depth of "(X)" is x+1.
// 
// 
// For example, the depth of "(((())))" is 4, the depth of "()()()" is 1, and the depth of "(())()" is 2.
// 
// Note that the depth of each correct parentheses sequence is uniquely defined using the above rules.
// For example, when evaluating the depth of "()()()" it does not matter whether we take X = "()" and Y = "()()" or we 
// take X = "()()" and Y = "()", the result will be the same in both cases.
// 
// 
// Given a string s that is a correct parentheses sequence, calculate and return the depth of s.
// 
// DEFINITION
// Class:ParenthesesDiv2Easy
// Method:getDepth
// Parameters:string
// Returns:int
// Method signature:int getDepth(string s)
// 
// 
// CONSTRAINTS
// -s will contain between 2 and 50 characters, inclusive.
// -Each character in s will be '(' or ')'.
// -s will be a correct parentheses sequence.
// 
// 
// EXAMPLES
// 
// 0)
// "(())"
// 
// Returns: 2
// 
// 
// The depth of "" is 0.
// Therefore, the depth of "()" is 1.
// Next, the depth of "(())" is the depth of "()" plus 1, which makes it 1+1 = 2.
// 
// 
// 1)
// "()()()"
// 
// Returns: 1
// 
// 
// The depth of "()()" is the maximum of the depth of "()" and the depth of "()". In other words, it is max(1,1) = 1.
// The depth of "()()()" is the maximum of the depth of "()()" and the depth of "()". Hence, this also equals max(1,1) = 1.
// 
// 
// 2)
// "(())()"
// 
// Returns: 2
// 
// The answer is max(2, 1) = 2.
// 
// 3)
// "((())())(((())(()))())"
// 
// Returns: 4
// 
// 
// 
// 4)
// "()"
// 
// Returns: 1
// 
// 
// 
// END CUT HERE

#line 91 "ParenthesesDiv2Easy.cc"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

const int N = 50;

class ParenthesesDiv2Easy {
	public:
	int getDepth(string s) {
		int ans = 0, p = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') p++;
			else p--;
			ans = max(ans, p);
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "(())"; int Arg1 = 2; verify_case(0, Arg1, getDepth(Arg0)); }
	void test_case_1() { string Arg0 = "()()()"; int Arg1 = 1; verify_case(1, Arg1, getDepth(Arg0)); }
	void test_case_2() { string Arg0 = "(())()"; int Arg1 = 2; verify_case(2, Arg1, getDepth(Arg0)); }
	void test_case_3() { string Arg0 = "((())())(((())(()))())"; int Arg1 = 4; verify_case(3, Arg1, getDepth(Arg0)); }
	void test_case_4() { string Arg0 = "()"; int Arg1 = 1; verify_case(4, Arg1, getDepth(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ParenthesesDiv2Easy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
