#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	unsigned long long tmp, ans = 0;
	tmp = n;
	tmp = tmp * (n - 1) / 2;
	tmp = tmp * (n - 2) / 3;
	tmp = tmp * (n - 3) / 4;
	tmp = tmp * (n - 4) / 5;
	ans += tmp;
	tmp = tmp * (n - 5) / 6;
	ans += tmp;
	tmp = tmp * (n - 6) / 7;
	ans += tmp;
	printf("%I64u\n", ans);
	return 0;
}
