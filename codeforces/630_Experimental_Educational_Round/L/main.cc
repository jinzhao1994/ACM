#include <cstdio>

int main() {
	char s1[7], s2[7];
	scanf("%s", s1 + 1);
	s2[1] = s1[1];
	s2[2] = s1[3];
	s2[3] = s1[5];
	s2[4] = s1[4];
	s2[5] = s1[2];
	long long x = 0, ans = 1;
	x = s2[1] - '0';
	x = x * 10 + s2[2] - '0';
	x = x * 10 + s2[3] - '0';
	x = x * 10 + s2[4] - '0';
	x = x * 10 + s2[5] - '0';
	ans = ans * x % 100000;
	ans = ans * x % 100000;
	ans = ans * x % 100000;
	ans = ans * x % 100000;
	ans = ans * x % 100000;
	printf("%05I64d\n", ans);
	return 0;
}
