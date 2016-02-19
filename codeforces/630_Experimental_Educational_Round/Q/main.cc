#include <cstdio>
#include <cmath>

const double PI = acos(-1.0);

int main() {
	double s3, s4, s5;
	double h3, h4, h5;
	double v3, v4, v5;
	s3 = 0.5 * 0.5 * tan(PI / 2 - PI / 3) * 3;
	s4 = 0.5 * 0.5 * tan(PI / 2 - PI / 4) * 4;
	s5 = 0.5 * 0.5 * tan(PI / 2 - PI / 5) * 5;
	h3 = sqrt(1 - pow(0.5 / sin(PI / 3), 2.));
	h4 = sqrt(1 - pow(0.5 / sin(PI / 4), 2.));
	h5 = sqrt(1 - pow(0.5 / sin(PI / 5), 2.));
	v3 = s3 * h3 / 3;
	v4 = s4 * h4 / 3;
	v5 = s5 * h5 / 3;
	double l3, l4, l5;
	scanf("%lf%lf%lf", &l3, &l4, &l5);
	printf("%.15f\n", v3 * l3 * l3 * l3 + v4 * l4 * l4 * l4 + v5 * l5 * l5 * l5);
	return 0;
}
