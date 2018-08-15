#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000;

int n;
int x[N], y[N], d[N];

bool cmp(int i, int j) {
    return x[i] < x[j];
}

int abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int main() {
    int total_cas;
    scanf("%d", &total_cas);
    for (int cas = 1; cas <= total_cas; cas++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
            d[i] = i;
        }
        sort(d, d + n, cmp);
        double ans = 0;
        for (int i = 1; i < n; i++) {
            if (ans == -1 || x[d[i - 1]] == x[d[i]]) {
                ans = -1;
            } else {
                double dx = abs(x[d[i - 1]] - x[d[i]]);
                double dy = abs(y[d[i - 1]] - y[d[i]]);
                double v = dy / dx;
                if (ans < v) {
                    ans = v;
                }
            }
        }
        if (ans == -1) {
            printf("-1\n");
        } else {
            printf("%.8f\n", ans);
        }
    }
    return 0;
}
