#include <cstdio>
#include <algorithm>

using namespace std;

int a[30];
int n, m;

int main() {
	scanf("%d", &n);
	for (; n != 0; n -= n & -n) {
		a[m++] = n & -n;
	}
	reverse(a, a + m);
	for (int i = 0; i < m; i++) {
		printf("%d ", __builtin_ffs(a[i]));
	}
	printf("\n");
	return 0;
}
