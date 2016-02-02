#include <cstdio>
#include <cstring>

const int N = 16;
const int INF = ~0u >> 1;

int n, m;
int a[N][N];
int popcount[1 << N];
bool dp[1 << N][N];
int ans[N][2];

inline void update(int i, int j) {
	dp[i][j] = true;
	int t = n / popcount[i] / 2 + 1;
	if (ans[j][0] > t) {
		ans[j][0] = t;
	}
}
int main() {
	int t, tt;
	scanf("%d", &t);
	for (int i = 0; i < (1 << 16); i++) {
		popcount[i] = __builtin_popcount(i);
	}
	for (tt = 1; tt <= t; tt++) {
		scanf("%d", &n);
		m = __builtin_ctz(n);
		for (int i = 0; i < n; i++) {
			ans[i][0] = INF;
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
				cnt += a[i][j];
			}
			if (cnt == n - 1) {
				ans[i][1] = 1;
			} else {
				ans[i][1] = n / 2 + 1;
			}
		}
		memset(dp, false, sizeof(dp));
		for (int i = 0; i < (1 << n); i++) if ((popcount[i] & popcount[i] - 1) == 0) {
			for (int j = 0; j < n; j++) if (i & 1 << j) {
				if (popcount[i] == 1) {
					update(i, j);
					continue;
				}
				for (int k = i; k != 0 && !dp[i][j]; k = k - 1 & i) if (popcount[k] == popcount[i] / 2 && (k & 1 << j) && dp[k][j]) {
					for (int l = 0; l < n; l++) {
						if (((i ^ k) & 1 << l) && dp[i ^ k][l] && a[j][l] == 1) {
							update(i, j);
						}
					}
				}
			}
		}
		printf("Case #%d:\n", tt);
		for (int i = 0; i < n; i++) {
			printf("%d %d\n", ans[i][0], ans[i][1]);
		}
	}
	return 0;
}
