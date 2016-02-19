#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	unsigned long long tmp, ans = 1;
	tmp = (unsigned long long)n * (n - 1) * (n - 2) * (n - 3) * (n - 4);
	ans = tmp / 120 * tmp;
	printf("%I64u\n", ans);
	return 0;
}
