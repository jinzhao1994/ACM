#include <cstdio>

const int N = 100000;

int n;
int a[N], ans;

int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%d", &n);
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			int t = a[i - 1];
			while ((i + ans) % 4 != 0) {
				if (a[i] > t && a[i] <= t + 10) {
					break;
				}
				ans++;
				t += 10;
			}
		}
		while ((n + ans) % 4 != 0) {
			ans++;
		}
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
