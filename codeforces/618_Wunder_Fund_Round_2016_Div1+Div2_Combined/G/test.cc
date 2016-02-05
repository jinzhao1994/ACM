#include <cstdio>
#include <vector>
#include <map>

using namespace std;

map<vector<int>, int> c;
int n = 3, m = 11;
int mm = 1 << m;

void test(int i) {
	vector<int> a;
	a.resize(n);
	int p = 0;
	for (int j = 0; j < m; j++) {
		if (i & 1 << j) {
			a[p++] = 1;
		} else {
			a[p++] = 2;
		}
		for (int k = p - 1; k > 0; k--) {
			if (a[k] == a[k - 1]) {
				a[k - 1]++;
				a[k] = 0;
				p--;
			} else {
				break;
			}
		}
		if (p == n) break;
	}
	c[a]++;
}

int main() {
	for (int i = 0; i < mm; i++) {
		test(i);
	}
	for (map<vector<int>, int>::iterator it = c.begin(); it != c.end(); it++) {
		int t = __gcd(it->second, mm);
		int sum = 0;
		for (int j = 0; j < n; j++) {
			printf("%d ", it->first[j]);
			sum += it ->first[j];
		}
		printf(", t = %d, p = %d / %d, sum = %d, sumk = %d\n", it -> second, it->second / t, mm / t, sum, sum * it->second);
	}
	return 0;
}
