#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200001;

int n, x, y;
int d[N];
vector<int> a[N];
int dp0[N], dp1[N];

void dfs(int i, int f) {
	int min1 = n, min2 = n, sum = 0;
	for (int j = 0; j < a[i].size(); j++) {
		if (a[i][j] != f) {
			dfs(a[i][j], i);
			sum += dp0[a[i][j]];
			int t = dp1[a[i][j]] - dp0[a[i][j]];
			if (t < min1) {
				swap(t, min1);
			}
			if (t < min2) {
				swap(t, min2);
			}
		}
	}
	if (sum == 0) {
		dp0[i] = dp1[i] = 1;
	} else {
		dp1[i] = sum + min1;
		dp0[i] = min(dp1[i], sum + min1 + min2 - 1);
	}
}
int main() {
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
		d[u]++;
		d[v]++;
	}
	if (x < y) {
		dfs(1, 0);
		printf("%I64d\n", (long long)y * (dp0[1] - 1) + (long long)x * (n - dp0[1]));
	} else {
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (d[i] == n - 1) {
				flag = false;
			}
		}
		if (flag) {
			printf("%I64d\n", (long long)y * (n - 1));
		} else {
			printf("%I64d\n", (long long)y * (n - 2) + x);
		}
	}
	return 0;
}
