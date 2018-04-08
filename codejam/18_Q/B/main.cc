#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100000;

int n;
int a[N], b[N], c[N];

int find_ans() {
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            if (b[i / 2] != a[i]) return i;
        } else {
            if (c[i / 2] != a[i]) return i;
        }
    }
    return -1;
}

int main() {
    int t, tt;
    scanf("%d", &tt);
    for (t = 1; t <= tt; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            if (i % 2) b[i / 2] = a[i];
            else c[i / 2] = a[i];
        }
        sort(b, b + n / 2);
        sort(c, c + n / 2 + n % 2);
        sort(a, a + n);
        int ans = find_ans();
        if (ans == -1) {
            printf("Case #%d: OK\n", t);
        } else {
            printf("Case #%d: %d\n", t, ans);
        }
    }
    return 0;
}
