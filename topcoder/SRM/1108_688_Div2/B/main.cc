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
// You have a string s of length n, where n is even.
// Your task is to change it into a correct parentheses sequence.
// In order to do that, you are allowed to flip some parentheses.
// Flipping a parenthesis changes it from '(' to ')' and vice versa.
// 
// 
// 
// There is always a way to change s into a correct parentheses sequence by doing at most (n/2)+1 flips.
// Find any such sequence of flips.
// Return a vector <int> containing a sequence of 0-based indices of parentheses in s you want to flip.
// 
// DEFINITION
// Class:ParenthesesDiv2Medium
// Method:correct
// Parameters:string
// Returns:vector <int>
// Method signature:vector <int> correct(string s)
// 
// 
// CONSTRAINTS
// -s will contain between 2 and 50 characters, inclusive.
// -The length of s will be even.
// -Each character in s will be '(' or ')'.
// 
// 
// EXAMPLES
// 
// 0)
// ")("
// 
// Returns: {0, 1 }
// 
// The returned sequence represents the following sequence of changes:
// 
// Start with the string ")(".
// Flip character 0. This produces the string "((".
// Flip character 1. This produces the string "()", which is a corrent parentheses sequence.
// 
// 
// 1)
// ")))))((((("
// 
// Returns: {0, 2, 4, 5, 7, 9 }
// 
// Performing the flips described by the returned sequence changes the given string into the corrent parentheses sequence 
// "()()()()()".
// The answer {2, 0, 4, 9, 7, 5} would also be valid, as the order in which we perform the flips does not matter.
// However, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} is not a valid answer: this sequence of flips does produce a correct 
// parentheses sequence but the number of flips is too large.
// As the length of s is 10, we may only perform at most 10/2 + 1 = 6 flips.
// 
// 2)
// "((()"
// 
// Returns: {1 }
// 
// 
// 
// 3)
// ")))(()(())))))"
// 
// Returns: {0, 1, 2 }
// 
// Here, {0, 1, 2, 3, 3} would also be a valid answer.
// Flipping the same parenthesis twice is allowed, even though it is clearly useless.
// 
// 4)
// "()()()()()()()()()()()()()"
// 
// Returns: { }
// 
// 
// 
// END CUT HERE

#line 89 "ParenthesesDiv2Medium.cc"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ParenthesesDiv2Medium {
	public:
	vector <int> correct(string s) {
		vector<int> ans;
		int p = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') p++;
			else if (p > 0) p--;
			else {
				p++;
				ans.push_back(i);
			}
		}
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == '(' && p > 0) {
				p-=2;
				ans.push_back(i);
			}
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = ")("; int Arr1[] = {0, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, correct(Arg0)); }
	void test_case_1() { string Arg0 = ")))))((((("; int Arr1[] = {0, 2, 4, 5, 7, 9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, correct(Arg0)); }
	void test_case_2() { string Arg0 = "((()"; int Arr1[] = {1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, correct(Arg0)); }
	void test_case_3() { string Arg0 = ")))(()(())))))"; int Arr1[] = {0, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, correct(Arg0)); }
	void test_case_4() { string Arg0 = "()()()()()()()()()()()()()"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, correct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ParenthesesDiv2Medium ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
