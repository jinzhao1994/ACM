#include <cstdio>
#include <cmath>
#include <complex>

using namespace std;

const int N = 1048576;
const double PI = acos(-1.0);

typedef complex<double> Point;

int n, m, nn;
Point sum[N], mul[N];

void maketree(int l, int r) {
	if (l == r) {
		if (l >= 1 && l <= n) {
			sum[l + r] = Point(1, 0);
		} else {
			sum[l + r] = Point(0, 0);
		}
		mul[l + r] = 1;
	} else {
		int t = l + r >> 1;
		maketree(l, t);
		maketree(t + 1, r);
		sum[l + r] = sum[l + t] + sum[t + 1 + r];
		mul[l + r] = Point(1, 0);
	}
}
void add(int l, int r, int i, double x) {
	if (l == r) {
		sum[l + r] *= mul[l + r];
		mul[l + r] = 1;
		sum[l + r] += sum[l + r] / abs(sum[l + r]) * x;
	} else {
		int t = l + r >> 1;
		mul[l + t] *= mul[l + r];
		mul[t + 1 + r] *= mul[l + r];
		mul[l + r] = 1;
		if (i <= t) {
			add(l, t, i, x);
		} else {
			add(t + 1, r, i, x);
		}
		sum[l + r] = sum[l + t] * mul[l + t] + sum[t + 1 + r] * mul[t + 1 + r];
	}
}
void multiply(int l, int r, int ll, int rr, Point x) {
	if (l == ll && r == rr) {
		mul[l + r] *= x;
	} else {
		int t = l + r >> 1;
		if (rr <= t) {
			multiply(l, t, ll, rr, x);
		} else if (ll > t) {
			multiply(t + 1, r, ll, rr, x);
		} else {
			multiply(l, t, ll, t, x);
			multiply(t + 1, r, t + 1, rr, x);
		}
		sum[l + r] = sum[l + t] * mul[l + t] + sum[t + 1 + r] * mul[t + 1 + r];
	}
}
int main() {
	scanf("%d%d", &n, &m);
	nn = ~0u >> __builtin_clz(n - 1);
	maketree(0, nn);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) {
			add(0, nn, y, z);
		} else {
			multiply(0, nn, y, n, exp(Point(0, -z / 180.0 * PI)));
		}
		printf("%.10f %.10f\n", real(sum[nn]), imag(sum[nn]));
	}
	return 0;
}
