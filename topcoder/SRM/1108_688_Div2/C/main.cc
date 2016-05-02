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
// You are given a string s.
// You are also given vector <int>s L and R, each with the same number of elements.
// These encode a set of conditions.
// For each valid i, you have to satisfy the following condition:
// the substring of s that begins at the 0-based index L[i] and ends at the 0-based index R[i] must be a correct 
// parentheses sequence.
// Note that the constraints guarantee that all the given ranges of indices are pairwise disjoint.
// 
// 
// You can only modify s in one way: in each step you can choose two characters of s and swap them.
// Return the minimal number of swaps needed to produce a string that satisfies all the given conditions.
// If it is impossible, return -1 instead.
// 
// DEFINITION
// Class:ParenthesesDiv2Hard
// Method:minSwaps
// Parameters:string, vector <int>, vector <int>
// Returns:int
// Method signature:int minSwaps(string s, vector <int> L, vector <int> R)
// 
// 
// CONSTRAINTS
// -s will contain between 1 and 50 characters, inclusive.
// -Each character in s will be '(' or ')'.
// -L will contain between 1 and 50 elements, inclusive.
// -L and R will contain the same number of elements.
// -For each valid i, 0 <= L[i] <= R[i] < |s|.
// -For different i and j, intervals [(L[i]), (R[i])] and [(L[j]), (R[j])] will not intersect.
// 
// 
// EXAMPLES
// 
// 0)
// ")("
// {0}
// {1}
// 
// Returns: 1
// 
// We have one condition:
// The substring that begins at index 0 and ends at index 1 must be a correct parentheses sequence.
// In this case, this means that the entire string s must be a correct parentheses sequence.
// 
// We can achieve that by swapping s[0] with s[1].
// This swap produces the string "()".
// 
// 1)
// "(())"
// {0,2}
// {1,3}
// 
// Returns: 1
// 
// The only way to satisfy both conditions is to change s into "()()".
// This can be done in 1 swap: by swapping s[1] with s[2].
// 
// 2)
// "(((())"
// {0,2}
// {1,3}
// 
// Returns: 2
// 
// This time we do swap(s[1],s[4]) and swap(s[3],s[5]).
// 
// 3)
// "((((((((("
// {0,2}
// {1,3}
// 
// Returns: -1
// 
// 
// 
// 4)
// "))()())((()()()()()())))(((((("
// {1,6,13,17,23,25}
// {4,7,16,20,24,28}
// 
// Returns: 5
// 
// 
// 
// 5)
// "("
// {0}
// {0}
// 
// Returns: -1
// 
// 
// 
// END CUT HERE

#line 108 "ParenthesesDiv2Hard.cc"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> l;
bool cmp(int i, int j) {
	return l[i] < l[j];
}

class ParenthesesDiv2Hard {
	public:
	int minSwaps(string s, vector <int> L, vector <int> R) {
		int n = s.length(), m = L.size();
		vector<bool> b(n);
		for (int i = 0; i < m; i++) {
			if ((R[i] - L[i] + 1) % 2 != 0) return -1;
			for (int j = L[i]; j <= R[i]; j++) b[j] = true;
		}
		l = L;
		vector<int> a(m);
		for (int i = 0; i < m; i++) a[i] = i;
		sort(a.begin(), a.end(), cmp);

		int ans1 = 0, ans2 = 0, p = 0;
		for (int i = 0; i < m; i++) {
			for (int j = L[a[i]]; j <= R[a[i]]; j++) {
				if (s[j] == '(') p++;
				else if (p > 0) p--;
				else {
					p++;
					ans1++;
				}
			}
			for (int j = R[a[i]]; j >= L[a[i]]; j--) {
				if (p > 0 && s[j] == '(') {
					p -= 2;
					ans2++;
				}
			}
		}
		for (int i = 0; i < n; i++) if (b[i] == false) {
			if (ans1 < ans2 && s[i] == ')') ans1++;
			if (ans1 > ans2 && s[i] == '(') ans2++;
		}
		if (ans1 == ans2) return ans1;
		return -1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1 || Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ")("; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "(())"; int Arr1[] = {0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "(((())"; int Arr1[] = {0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "((((((((("; int Arr1[] = {0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "))()())((()()()()()())))(((((("; int Arr1[] = {1,6,13,17,23,25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,7,16,20,24,28}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(4, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "("; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(5, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = ")))))))))((()())"; int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(6, Arg3, minSwaps(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ParenthesesDiv2Hard ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
