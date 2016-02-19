#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[26];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	long long ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (i != n - 1 && a[i] >= a[i + 1]) {
			a[i] = a[i + 1] - 1;
		}
		a[i] = max(a[i], 0);
		ans += a[i];
	}
	printf("%I64d\n", ans);
	return 0;
}
