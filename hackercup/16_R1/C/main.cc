#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100001;

int n;
long long a, b;
long long c[N], d[N];

long long cal(long long a, int i) {
	long long t = a / d[n];
	long long ans = t * c[i] * c[i];
	t = a % d[n];
	if (t > d[i - 1]) {
		t = min(t - d[i - 1], c[i]);
		ans += t * t;
	}
	return ans;
}

int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%d%lld%lld", &n, &a, &b);
		d[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &c[i]);
			d[i] = d[i - 1] + c[i];
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += cal(b, i) - cal(a, i);
		}
		printf("Case #%d: %.10lf\n", tt, (double)ans / (b - a) / 2);
	}
	return 0;
}
