#include <cstdio>

inline int in() {
	char c = getchar();
	int ans = 0;
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans;
}

const int N = 5000001;
int mpf[N];
int sc[N];
int sum[N];
int p[N];
int pn;

int main() {
	int i, j, t, a, b;
	for (i = 2; i < N; i++) {
		if (mpf[i] == 0) {
			mpf[i] = p[pn++] = i;
		}
		for (j = 0; j < pn && i * p[j] < N && p[j] <= mpf[i]; j++) {
			mpf[i * p[j]] = p[j];
		}
	}
	sc[0] = sc[1] = 0;
	for (i = 2; i < N; i++) {
		sc[i] = sc[i / mpf[i]] + 1;
	}
	sum[0] = 0;
	for (i = 2; i < N; i++) {
		sum[i] = sum[i - 1] + sc[i];
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", sum[a] - sum[b]);
	}
	return 0;
}
