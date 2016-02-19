#include <cstdio>

int main() {
	long long n;
	scanf("%I64d", &n);
	n = (n % 360 + 360) % 360;
	n = (n + 45) % 360;
	printf("%I64d\n", (n - 1) / 90);
	return 0;
}
