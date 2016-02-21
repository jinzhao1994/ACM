#include <cstdio>

char a[100][100];
int n, ans, sum;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'C') {
				sum++;
			}
		}
		ans += sum * (sum - 1) / 2;
	}
	for (int j = 0; j < n; j++) {
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i][j] == 'C') {
				sum++;
			}
		}
		ans += sum * (sum - 1) / 2;
	}
	printf("%d\n", ans);
	return 0;
}
