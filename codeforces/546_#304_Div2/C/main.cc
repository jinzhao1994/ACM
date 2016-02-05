#include <queue>
#include <map>
#include <utility>
#include <cstdio>

using namespace std;

map<pair<queue<int>, queue<int> >, int> c;
int n, k1, k2;
queue<int> a, b;
pair<int, int> ans;

pair<int, int> cal() {
	int step = 1;
	c[make_pair(a, b)] = step++;
	while (!a.empty() && !b.empty()) {
		int x = a.front(), y = b.front();
		a.pop();
		b.pop();
		if (x < y) {
			b.push(x);
			b.push(y);
		} else {
			a.push(y);
			a.push(x);
		}
		int &tmp = c[make_pair(a, b)];
		if (tmp == 0) {
			tmp = step++;
		} else {
			return make_pair(-1, -1);
		}
	}
	return make_pair(step - 2, (int)a.empty() + 1);
}
int main() {
	int i, x;
	scanf("%d", &n);
	scanf("%d", &k1);
	for (i = 0; i < k1; i++) {
		scanf("%d", &x);
		a.push(x);
	}
	scanf("%d", &k2);
	for (i = 0; i < k2; i++) {
		scanf("%d", &x);
		b.push(x);
	}
	ans = cal();
	if (ans.first == -1) {
		printf("-1\n");
	} else {
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}
