#include <cstdio>

int main() {
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	x2 = x2 - x1 + 1;
	y2 = y2 - y1 + 1;
	printf("%I64d\n", (long long)x2 / 2 * y2 + (x2 & 1) * (y2 + 1) / 2);
	return 0;
}
