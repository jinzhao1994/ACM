#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(0));
	int n, k;
	k = rand() % 30000 + 1;
	n = rand() % k + 1;
	printf("%d %d\n", n, k);
	return 0;
}
