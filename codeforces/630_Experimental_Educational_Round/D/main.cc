#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	printf("%I64u\n", 3ull * n * (n + 1) + 1);
	return 0;
}
