#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

int l, n, m, d;
int w[100000];
set<pair<long long, int> > b;
multiset<long long> c;

int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%d%d%d%d", &l, &n, &m, &d);
		b.clear();
		c.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
			b.insert(make_pair((long long)w[i], i));
		}
		for (int i = 0; i < m && i < l; i++) {
			c.insert((long long)d);
		}
		long long ans = 0;
		for (int i = 0; i < l; i++) {
			pair<long long, int> tmp1 = *b.begin();
			b.erase(b.begin());
			long long tmp2 = *c.begin();
			c.erase(c.begin());
			tmp2 = max(tmp2, tmp1.first + d);
			ans = max(ans, tmp2);
			tmp1.first += w[tmp1.second];
			tmp2 += d;
			b.insert(tmp1);
			c.insert(tmp2);
		}
		printf("Case #%d: %lld\n", tt, ans);
	}
	return 0;
}
