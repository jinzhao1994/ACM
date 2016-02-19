#include <cstdio>
#include <cmath>

const double PI = acos(-1.0);

int main() {
	double n, r;
	scanf("%lf%lf", &n, &r);
	double p = PI / n;
	double l = r * sin(p);
	double s = l * tan((PI - 3 * p) / 2) * l;
	double ss = r * cos(p) * l;
	printf("%.15f\n", n * (ss - s));
	return 0;
}
