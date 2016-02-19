#include <cstdio>

const int N = 501;

int n, m;
bool a[N][N];
int sum[N];
bool vis[N];
char ans[N];

int abs(int x) {
	if (x >= 0) {
		return x;
	}
	return -x;
}
void dfs(int i, int c) {
	ans[i] = 'a' + c;
	vis[i] = true;
	for (int j = 1; j <= n; j++) {
		if (a[i][j] && !vis[j]) {
			dfs(j, 2 - c);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = true;
		}
		a[i][i] = false;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = false;
		a[y][x] = false;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i] +=a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (sum[i] == 0) {
			ans[i] = 'b';
		} else if (vis[i] == false) {
			dfs(i, 0);
		}
	}
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i][j]) {
				if (abs(ans[i] - ans[j]) <= 1) {
					flag = false;
				}
			} else {
				if (abs(ans[i] - ans[j]) > 1) {
					flag = false;
				}
			}
		}
	}
	if (flag) {
		printf("Yes\n");
		for (int i = 1; i <= n; i++) {
			printf("%c", ans[i]);
		}
		printf("\n");
	} else {
		printf("No\n");
	}
	return 0;
}
