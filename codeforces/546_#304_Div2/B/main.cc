#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[3000];

int main() {
	int i, x;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int cur = 1, ans = 0;
	for (i = 0; i < n; i++) {
		if (cur < a[i]) {
			cur = a[i];
		}
		ans += cur - a[i];
		cur++;
	}
	printf("%d\n", ans);
	return 0;
}
