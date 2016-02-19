#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


const int mod = 1000000007;
const int K = 32768, K2 = K * 2;
const int mod1 = (31 * 31 << 20) + 1, mod2 = (17 * 59 << 20) + 1, mod3 = (3 << 18) + 1;
const int g1 = 3, g2 = 6, g3 = 10;
const int inv1 = 346612643, inv2 = 408151354, inv3 = 210725;

struct DP {
	int v[K], n;
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
void NTT(int a[], int n, int oper, int mod, int g) {
	for (int i = 1, j = 0; i < n; i++) {
		for (int s = n; j ^= s >>= 1, ~j & s; );
		if (i < j) swap(a[i], a[j]);
	}
	for (int m = 1; m < n; m *= 2) {
		int w = pow(g, (mod - 1) / (2 * m), mod);
		if (oper == -1) w = pow(w, mod - 2, mod);
		for (int i = 0; i < n; i += m * 2) {
			int unit = 1;
			for (int j = 0; j < m; j++) {
				int &x = a[i + j + m], &y = a[i + j], t = (long long)unit * x % mod;
				x = y - t;
				y = y + t;
				if (x < 0) {
					x += mod;
				}
				if (y >= mod) {
					y -= mod;
				}
				unit = (long long)unit * w % mod;
			}
		}
	}
	if (oper == -1) {
		int inv = pow(n, mod - 2, mod);
		for (int i = 0; i < n; i++) a[i] = (long long)a[i] * inv % mod;
	}
}
void mul(int a[], int b[], int c[], int mod, int g) {
	static int A[K2], B[K2];
	for (int i = 0; i < K; i++) {
		A[i] = a[i] % mod;
		B[i] = b[i] % mod;
	}
	for (int i = K; i < K2; i++) {
		A[i] = B[i] = 0;
	}
	NTT(A, K2, 1, mod, g);
	NTT(B, K2, 1, mod, g);
	for (int i = 0; i < K2; i++) {
		c[i] = (long long)A[i] * B[i] % mod;
	}
	NTT(c, K2, -1, mod, g);
}
DP operator * (DP a, DP b) {
	for (int i = 0; i < K; i++) {
		a.v[i] = (long long)a.v[i] * pow(2, b.n * i, mod) % mod;
	}
	static int c1[K2], c2[K2], c3[K2];
	mul(a.v, b.v, c1, mod1, g1);
	mul(a.v, b.v, c2, mod2, g2);
	mul(a.v, b.v, c3, mod3, g3);
	DP ans;
	ans.n = a.n + b.n;
	for (int i = 0; i < K; i++) {
		__int128 k = 0;
		k += (__int128)c1[i] * inv1 * mod2 * mod3;
		k += (__int128)c2[i] * inv2 * mod1 * mod3;
		k += (__int128)c3[i] * inv3 * mod1 * mod2;
		const __int128 MM = (__int128)mod1 * mod2 * mod3;
		k %= MM;
		ans.v[i] = k % mod;
	}
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
