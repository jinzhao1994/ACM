#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100001;
const double PI = acos(-1.0);

int n, m;
int r[N], h[N], l[N];
long long v[N], v2[N];
double dp[N];

double get(int i) {
	double ans = 0;
	for (; i > 0; i -= i & -i) {
		ans = max(ans, dp[i]);
	}
	return ans;
}
void set(int i, double x) {
	for (; i < N; i += i & -i) {
		dp[i] = max(dp[i], x);
	}
}
inline double getv(int i) {
	return PI * r[i] * r[i] * h[i];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &r[i], &h[i]);
		v2[i] = v[i] = (long long)r[i] * r[i] * h[i];
	}
	sort(v2, v2 + n);
	m = unique(v2, v2 + n) - v2;
	double ans = 0;
	for (int i = 0; i < n; i++) {
		int d = lower_bound(v2, v2 + n, v[i]) - v2 + 1;
		double x = getv(i) + get(d - 1);
		set(d, x);
		ans = max(ans, x);
	}
	printf("%.10f\n", ans);
	return 0;
}
