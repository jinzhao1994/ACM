#include <cstdio>

int n;
char s[2][1003];

void put(int i, int j) {
	s[i ^ 1][j] = 'X';
	if (s[i][j] == 'X') {
		return;
	}
	for (int k = j; s[i][k] == '.'; k--) {
		s[i][k] = 'X';
	}
	for (int k = j + 1; s[i][k] == '.'; k++) {
		s[i][k] = 'X';
	}
}
int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%d", &n);
		scanf("%s", &s[0][1]);
		scanf("%s", &s[1][1]);
		s[0][0] = s[1][0] = s[0][n + 1] = s[1][n + 1] = 'X';
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (s[0][i - 1] == 'X' && s[0][i] == '.' && s[0][i + 1] == 'X') {
				put(1, i);
				ans++;
			}
			if (s[1][i - 1] == 'X' && s[1][i] == '.' && s[1][i + 1] == 'X') {
				put(0, i);
				ans++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (s[0][i] == '.' && s[0][i - 1] == 'X') {
				ans++;
			}
			if (s[1][i] == '.' && s[1][i - 1] == 'X') {
				ans++;
			}
		}
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
