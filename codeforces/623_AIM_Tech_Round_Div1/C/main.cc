#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const int N = 100000;
const long long INF = ~0ull >> 2;
const int MAX_V = ~0u >> 2;

int n;
pair<int, int> a[N];
int minyl[N], maxyl[N], minyr[N], maxyr[N];

int abs(int x) {
	if (x >= 0) {
		return x;
	}
	return -x;
}
long long square(int x) {
	return (long long)x * x;
}
int sqrt(long long t) {
	int l = 0, r = MAX_V;
	while (l != r) {
		int tmp = (l + r) / 2;
		if (square(tmp) <= t) {
			l = tmp + 1;
		} else {
			r = tmp;
		}
	}
	return l - 1;
}
bool test(int l, int r, long long t) {
	int minx = a[l].first, maxx = a[r].first;
	int miny = 0, maxy = 0;
	if (l != 0) {
		miny = min(miny, minyl[l - 1]);
		maxy = max(maxy, maxyl[l - 1]);
	}
	if (r != n) {
		miny = min(miny, minyr[r + 1]);
		maxy = max(maxy, maxyr[r + 1]);
	}
	int x = max(abs(minx), abs(maxx));
	int y = max(abs(miny), abs(maxy));
	if (square(x) + square(y) <= t && square(maxy - miny) <= t && square(maxx - minx) <= t) {
		return true;
	}
	return false;
}
bool can(long long t) {
	if (square(maxyr[0] - minyr[0]) <= t) {
		return true;
	}
	if (square(a[n - 1].first - a[0].first) <= t) {
		return true;
	}
	int v = sqrt(t);
	for (int i = 0; i < n; i++) {
		if (a[i].first < 0) {
			int r1 = upper_bound(a, a + n, make_pair(a[i].first + v, MAX_V)) - a;
			int r2 = upper_bound(a, a + n, make_pair(-a[i].first, MAX_V)) - a;
			if (test(i, r1 - 1, t) || test(i, r2 - 1, t)) {
				return true;
			}
		} else {
			int l1 = lower_bound(a, a + n, make_pair(a[i].first - v, -MAX_V)) - a;
			int l2 = lower_bound(a, a + n, make_pair(-a[i].first, -MAX_V)) - a;
			if (test(l1, i, t) || test(l2, i, t)) {
				return true;
			}
		}
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	minyl[0] = maxyl[0] = a[0].second;
	for (int i = 1; i < n; i++) {
		minyl[i] = min(minyl[i - 1], a[i].second);
		maxyl[i] = max(maxyl[i - 1], a[i].second);
	}
	minyr[n - 1] = maxyr[n - 1] = a[n - 1].second;
	for (int i = n - 2; i >= 0; i--) {
		minyr[i] = min(minyr[i + 1], a[i].second);
		maxyr[i] = max(maxyr[i + 1], a[i].second);
	}
	long long l = 0, r = INF;
	while (l != r) {
		long long t = (l + r) / 2;
		if (can(t)) {
			r = t;
		} else {
			l = t + 1;
		}
	}
	printf("%I64d\n", l);
	return 0;
}
