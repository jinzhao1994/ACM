#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100001;
const int INF = 1000000000;

struct Node {
	Node *s[26];
	bool match;
	Node *clear() {
		memset(s, 0, sizeof(s));
		match = false;
		return this;
	}
};

Node a[N], *ap, *root;
char s[N];
int n, k;

void insert(char *s) {
	Node *cur = root;
	while (*s) {
		int x = *s - 'a';
		if (cur->s[x] == NULL) {
			cur->s[x] = (ap++)->clear();
		}
		cur = cur->s[x];
		s++;
	}
	cur->match = true;
}
inline void update(int &a, int b) {
	if (a > b) {
		a = b;
	}
}
int dfs(Node *root, vector<int> &ans) {
	int num = 0;
	if (root->match) {
		num++;
	}
	ans.resize(num + 1, 0);
	for (int i = 0; i < 26; i++) {
		if (root->s[i]) {
			vector<int> cur;
			int t = dfs(root->s[i], cur);
			ans.resize(num + 1 + t, INF);
			for (int j = num; j >= 0; j--) {
				for (int k = t; k >= 0; k--) {
					update(ans[j + k], ans[j] + cur[k] + 1);
				}
			}
			num += t;
		}
	}
	return num;
}
int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%d%d", &n, &k);
		ap = a;
		root = (ap++)->clear();
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			insert(s);
		}
		vector<int> ans;
		dfs(root, ans);
		printf("Case #%d: %d\n", tt, ans[k] * 2 + k);
	}
	return 0;
}
