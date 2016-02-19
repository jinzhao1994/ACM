#include <cstdio>
#include <cmath>

int main() {
	double px, py, vx, vy;
	double a, b, c, d;
	scanf("%lf%lf%lf%lf", &px, &py, &vx, &vy);
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	double len = sqrt(vx * vx + vy * vy);
	vx /= len;
	vy /= len;
	printf("%.10f %.10f\n", px + vx * b, py + vy * b);
	printf("%.10f %.10f\n", px - vy * a / 2, py + vx * a / 2);
	printf("%.10f %.10f\n", px - vy * c / 2, py + vx * c / 2);
	printf("%.10f %.10f\n", px - vy * c / 2 - vx * d, py + vx * c / 2 - vy * d);
	printf("%.10f %.10f\n", px + vy * c / 2 - vx * d, py - vx * c / 2 - vy * d);
	printf("%.10f %.10f\n", px + vy * c / 2, py - vx * c / 2);
	printf("%.10f %.10f\n", px + vy * a / 2, py - vx * a / 2);
	return 0;
}
