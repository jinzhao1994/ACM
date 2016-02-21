#pragma comment(linker, "/STACK:102400000, 102400000")
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100001;
const int K = 20;

vector<int> a[N];
int f[N][K], h[N], sz[N];
long long dp[N], dp2[N];
int n, m;

void dfs(int i, int fa) {
	h[i] = h[fa] + 1;
	sz[i] = 1;
	f[i][0] = fa;
	for (int k = 1; k < K; k++) {
		f[i][k] = f[f[i][k - 1]][k - 1];
	}
	for (int j = 0; j < a[i].size(); j++) {
		if (a[i][j] != fa) {
			dfs(a[i][j], i);
			sz[i] += sz[a[i][j]];
			dp[i] += dp[a[i][j]] + sz[a[i][j]];
		}
	}
}
void dfs2(int i, int fa) {
	if (fa == 0) {
		dp2[i] = 0;
	} else {
		dp2[i] = dp2[fa] + n - sz[i] + dp[fa] - dp[i] - sz[i];
	}
	for (int j = 0; j < a[i].size(); j++) {
		if (a[i][j] != fa) {
			dfs2(a[i][j], i);
		}
	}
}
double cal(int x, int y) {
	if (h[x] < h[y]) {
		swap(x, y);
	}
	int u = x, v = y;
	for (int k = K - 1; k >= 0; k--) {
		if (h[f[u][k]] >= h[v]) {
			u = f[u][k];
		}
	}
	for (int k = K - 1; k >= 0; k--) {
		if (f[u][k] != f[v][k]) {
			u = f[u][k];
			v = f[v][k];
		}
	}
	double ans;
	if (u != v) {
		u = f[u][0];
		ans = 1 + h[x] - h[u] + h[y] - h[u];
		ans += (double)dp[x] / sz[x];
		ans += (double)dp[y] / sz[y];
	} else {
		u = x;
		v = y;
		for (int k = K - 1; k >= 0; k--) {
			if (h[f[u][k]] >= h[v] + 1) {
				u = f[u][k];
			}
		}
		ans = 1 + h[x] - h[v];
		ans += (double)dp[x] / sz[x];
		ans += (double)(dp[y] - dp[u] - sz[u] + dp2[y]) / (sz[y] - sz[u] + n - sz[y]);
	}
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	dfs2(1, 0);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%.10f\n", cal(x, y));
	}
	return 0;
}
