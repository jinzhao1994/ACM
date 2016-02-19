#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	double delta = sqrt((double)(b * b - 4 * a * c));
	double x0 = (-b + delta) / (2 * a);
	double x1 = (-b - delta) / (2 * a);
	printf("%.10f\n", max(x0, x1));
	printf("%.10f\n", min(x0, x1));
	return 0;
}
