#include <cstdio>

const int P = 1000000000;
const int M = 50;

struct Matrix {
	double a[M][M];
};

Matrix operator * (const Matrix &a, const Matrix &b) {
	Matrix ans;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			ans.a[i][j] = 0;
			for (int k = 0; k < M; k++) {
				ans.a[i][j] += a.a[i][k] * b.a[k][j];
			}
		}
	}
	return ans;
}
Matrix pow(Matrix x, int n) {
	Matrix ans;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			ans.a[i][j] = 0;
		}
		ans.a[i][i] = 1;
	}
	while (n) {
		if (n & 1) {
			ans = ans * x;
		}
		x = x * x;
		n >>= 1;
	}
	return ans;
}

int n, p;
double p1, p2; // p1, p2 分别为放1的概率和放2的概率
double q[M][M]; // q[i][j] 长度为i的串中，以j开头的概率
double dp[M][M]; // dp[i][j] 长度为i的串，且以j开头，期望
Matrix c, d;

int main() {
	scanf("%d%d", &n, &p);
	p1 = (double)p / P;
	p2 = 1 - p1;

	q[1][1] = p1;
	q[1][2] = p2;
	double qq = 1; // 长为i - 1的格子中，生成串i - 1, ..., 2的概率，最后一个格子还未填
	for (int i = 2; i < M; i++) {
		for (int j = 1; j < i - 1; j++) {
			q[i][j] = q[i - 1][j];
		}
		q[i][i - 1] = q[i - 1][i - 1] - qq * p1 * p1;
		q[i][i] = (qq * p1 * p1 + q[i - 1][i]) * (1 - qq * p2);
		q[i][i + 1] = (qq * p1 * p1 + q[i - 1][i]) * (qq * p2);
		qq = (qq * p1 * p1 + q[i - 1][i]) * qq;
	}

	dp[1][1] = 1;
	dp[1][2] = 2;
	for (int i = 2; i < M; i++) {
		for (int j = 1; j < M; j++) {
			double sump = 0;
			if (j == 1) {
				for (int k = 2; k < M; k++) {
					dp[i][j] += q[i - 1][k] * dp[i - 1][k];
					sump += q[i - 1][k];
				}
			} else {
				for (int k = 1; k < j; k++) {
					dp[i][j] += q[i - 1][k] * dp[i - 1][k];
					sump += q[i - 1][k];
				}
			}
			dp[i][j] = dp[i][j] / sump + j;
		}
	}

	double ans = 0;
	if (n < M) {
		for (int j = 1; j < M; j++) {
			ans += dp[n][j] * q[n][j];
		}
		printf("%.15f\n", ans);
		return 0;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			c.a[i][j] = 0;
		}
	}
	for (int j = 1; j < M; j++) {
		double sump = 0;
		if (j == 1) {
			for (int k = 2; k < M; k++) {
				c.a[j][k] = q[M - 1][k];
				sump += q[M - 1][k];
			}
		} else {
			for (int k = 1; k < j; k++) {
				c.a[j][k] = q[M - 1][k];
				sump += q[M - 1][k];
			}
		}
		for (int k = 1; k < M; k++) {
			c.a[j][k] /= sump;
		}
		sump = 0;
		for (int k = 1; k < M; k++) {
			sump += c.a[j][k];
		}
		c.a[j][0] = j;
	}
	c.a[0][0] = 1;

	d = pow(c, n - (M - 1));
	dp[M - 1][0] = 1;
	for (int j = 1; j < M; j++) {
		for (int k = 0; k < M; k++) {
			ans += d.a[j][k] * dp[M - 1][k] * q[M - 1][j];
		}
	}
	printf("%.15f\n", ans);
	return 0;
}
