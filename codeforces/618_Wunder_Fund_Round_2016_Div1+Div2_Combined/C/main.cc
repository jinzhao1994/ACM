#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const int N = 100001;

typedef pair<int, int> Point;

int n;
Point a[N];
int ans[4] = {0, 1, 2, 0};

long long area(Point a, Point b, Point c) {
	long long x1 = a.first - b.first;
	long long x2 = b.first - c.first;
	long long y1 = a.second - b.second;
	long long y2 = b.second - c.second;
	long long ans = x1 * y2 - x2 * y1;
	if (ans < 0) {
		ans = -ans;
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
		long long x1 = a[i].first - a[ans[1]].first;
		long long x2 = a[i].first - a[ans[2]].first;
		long long y1 = a[i].second - a[ans[1]].second;
		long long y2 = a[i].second - a[ans[2]].second;
		if (x2 * y1 == x1 * y2) {
			if (x1 * x2 < 0 || y1 * y2 < 0) {
				ans[2] = i;
			}
		} else {
			if (ans[3] == 0 || area(a[ans[1]], a[ans[2]], a[ans[3]]) > area(a[ans[1]], a[ans[2]], a[i])) {
				ans[3] = i;
			}
		}
	}
	printf("%d %d %d\n", ans[1], ans[2], ans[3]);
	return 0;
}
