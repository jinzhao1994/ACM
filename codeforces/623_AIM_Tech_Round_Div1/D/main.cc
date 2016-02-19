#include <cstdio>

const int N = 100;
const double eps = 1e-9;

int n;
int p[N];
double g[N]; //当前情况，每个人已经被猜出来的概率
double ans, c;

void take(int i, int k) {
	double tk = 1;
	for (int j = 0; j < n; j++) {
		if (j != k) {
			tk *= g[j];
		} else {
			tk *= (1 - g[j]);
		}
	}
	tk = tk * (double)p[k] / 100 * i;
	g[k] += (1 - g[k]) * p[k] / 100;
	double y = tk - c;
	double t = ans + y;
	c = (t - ans) - y;
	ans = t;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; true; i++) {
		if (i <= n) {
			take(i, i - 1);
			continue;
		}
		double mulg = 1;
		for (int j = 0; j < n; j++) {
			mulg *= g[j];
		}
		if (mulg + eps >= 1) {
			break;
		}
		int k = -1;
		double tk = -1;
		for (int j = 0; j < n; j++) {
			double tj = mulg / g[j] * (1 - g[j]) * p[j] / 100;
			if (tj > tk) {
				k = j;
				tk = tj;
			}
		}
		take(i, k);
	}
	printf("%.10f\n", ans);
	return 0;
}
