#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100001;

int n, p;
int a[N];
long long sum[N];

int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%d%d", &n, &p);
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += upper_bound(sum, sum + n + 1, sum[i - 1] + p) - sum - i;
		}
		printf("Case #%d: %lld\n", tt, ans);
	}
	return 0;
}
