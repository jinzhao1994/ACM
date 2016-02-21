#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 367;

int n;
int l[N], r[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char x;
		int y, z;
		scanf(" %c%d%d", &x, &y, &z);
		if (x == 'M') {
			for (int j = y; j <= z; j++) {
				l[j]++;
			}
		} else {
			for (int j = y; j <= z; j++) {
				r[j]++;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < N; i++) {
		ans = max(ans, 2 * min(l[i], r[i]));
	}
	printf("%d\n", ans);
	return 0;
}
