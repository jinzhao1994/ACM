#include <cstdio>
#include <cmath>

const double PI = acos(-1.0);

int main() {
	double n, r;
	scanf("%lf%lf", &n, &r);
	double p1 = PI / n, p2 = PI / (2 * n), p3 = PI - p1 - p2;
	printf("%e %e %e\n", p1, p2, p3);
	double l3 = r, l2 = l3 / sin(p3) * sin(p2), l1 = l3 / sin(p3) * sin(p1);
	printf("%e %e %e\n", l1, l2, l3);
	printf("%e\n",  (l1 + l2 + l3) * (l1 + l2 - l3) * (l1 + l3 - l2) * (l2 + l3 - l1));
	double s = sqrt((l1 + l2 + l3) * (l1 + l2 - l3) * (l1 + l3 - l2) * (l2 + l3 - l1)) / 4;
	printf("%.15f\n", n * 2 * s);
	return 0;
}
