#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[50][50];
int ans[50];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			ans[i] = max(ans[i], a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] == n - 1) {
			ans[i] = n;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
