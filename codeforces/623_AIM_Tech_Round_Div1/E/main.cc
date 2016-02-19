#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


const int mod = 1000000007;
const int K = 32768, K2 = K * 2;

struct DP {
	int v[K2], n;
	DP() {
		memset(v, 0, sizeof(v));
	}
};

int fact[K];

inline int pow(int x, int n, int mod) {
	int ans = 1;
	while (n) {
		if (n & 1) {
			ans = (long long)ans * x % mod;
		}
		x = (long long)x * x % mod;
		n >>= 1;
	}
	return ans;
}
inline void add(int &a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}
void mul(int a[], int b[], int c[], int n) {
	if (n <= 16) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				add(c[i + j], (long long)a[i] * b[j] % mod);
			}
		}
	} else {
		int m = n / 2;
		int *d = new int[n];
		memset(d, 0, sizeof(int) * n);
		mul(a, b, d, m);
		for (int i = 0; i < n; i++) {
			add(c[i], d[i]);
			add(c[i + m], mod - d[i]);
		}
		memset(d, 0, sizeof(int) * n);
		mul(a + m, b + m, d, m);
		for (int i = 0; i < n; i++) {
			add(c[i + n], d[i]);
			add(c[i + m], mod - d[i]);
		}
		delete [] d;
		for (int i = 0; i < m; i++) {
			add(a[i], a[i + m]);
			add(b[i], b[i + m]);
		}
		mul(a, b, c + m, m);
		for (int i = 0; i < m; i++) {
			add(a[i], mod - a[i + m]);
			add(b[i], mod - b[i + m]);
		}
	}
}
DP operator * (DP a, DP b) {
	for (int i = 0; i < K; i++) {
		a.v[i] = (long long)a.v[i] * pow(2, b.n * i, mod) % mod;
	}
	DP ans;
	ans.n = a.n + b.n;
	mul(a.v, b.v, ans.v, K);
	return ans;
}
DP cal(int n) {
	DP x, ans;
	ans.n = 0;
	ans.v[0] = 1;
	x.n = 1;
	for (int i = 1; i < K; i++) {
		x.v[i] = pow(fact[i], mod - 2, mod);
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

int main() {
	fact[0] = 1;
	for (int i = 1; i < K; i++) {
		fact[i] = (long long)fact[i - 1] * i % mod;
	}
	long long n;
	int k;
	cin >> n >> k;
	if (n > k) {
		cout << 0 << endl;
		return 0;
	}
	DP dp = cal(n);
	int ans = 0;
	int c = 1;
	for (int i = 0; i <= k; i++) {
		ans = (ans + (long long)dp.v[i] * fact[i] % mod * c) % mod;
		c = (long long)c * (k - i) % mod * pow(i + 1, mod - 2, mod) % mod;
	}
	cout << ans << endl;
	return 0;
}
