#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int k, n, w;
	scanf("%d%d%d", &k, &n, &w);
	printf("%d\n", max(0, k * w * (w + 1) / 2 - n));
	return 0;
}
