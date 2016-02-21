#include <cstdio>

const int mod = 1000000007;
const int N = 100001;
const int M = 2001;

int c[M][M];
int n, m, tot, pre;
char s[N];

inline int regular(int x) {
	if (x >= mod) {
		return x - mod;
	}
	if (x < 0) {
		return x + mod;
	}
	return x;
}
inline int cal(int i, int j) {
	if (j == 0) {
		return 1;
	}
	return regular(c[i + j][j] - c[i + j][j - 1]);
}
int main() {
	c[0][0] = 1;
	for (int i = 1; i < M; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++) {
			c[i][j] = regular(c[i - 1][j - 1] + c[i - 1][j]);
		}
	}
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	for (int i = 0; i < m; i++) {
		if (s[i] == '(') {
			tot++;
		} else {
			tot--;
		}
		if (tot < -pre) {
			pre = -tot;
		}
	}
	int ans = 0;
	for (int l = 0; l <= n - m; l++) {
		int r = n - m - l;
		for (int k = 0; k <= l; k++) {
			int ll = k, lr = l - ll;
			int rl = ll - lr + tot, rr;
			if (ll - lr >= pre && r >= rl && ((r - rl) & 1) == 0) {
				rl = rl + ((r - rl) >> 1);
				rr = r - rl;
				ans = regular(ans + (long long)cal(ll, lr) * cal(rl, rr) % mod);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
