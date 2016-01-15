#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2000;
const int M = N * N;

int n, m;
int x[N], y[N], num[N];
int a[M], b[M], c[M], d[M];
long long ans;

bool cmp(int x,int y) {
	return a[x] < a[y];
}
int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x[i], &y[i]);
		}
		m = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				a[m] = (x[i] - x[j]) * (x[i] - x[j]) +
					(y[i] - y[j]) * (y[i] - y[j]);
				b[m] = i;
				c[m] = j;
				d[m] = m;
				m++;
			}
		}
		sort(d, d + m, cmp);
		ans = 0;
		int l = 0, r = 0;
		while (l < m) {
			while (r < m && a[d[r]] == a[d[l]]) {
				r++;
			}
			for (int i = l; i < r; i++) {
				ans += num[b[d[i]]]++;
				ans += num[c[d[i]]]++;
			}
			for (int i = l; i < r; i++) {
				num[b[d[i]]] = 0;
				num[c[d[i]]] = 0;
			}
			l = r;
		}
		printf("Case #%d: %lld\n", tt, ans);
	}
	return 0;
}
