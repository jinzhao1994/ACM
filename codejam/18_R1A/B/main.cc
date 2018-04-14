#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1001;

int n, m, tot;
int x[N], y[N], z[N];

bool can(long long t) {
    vector<long long> c;
    for (int i = 1; i <= n; i++) {
        if (z[i] <= t) {
            c.push_back(min((t - z[i]) / y[i], (long long) x[i]));
        }
    }
    sort(c.begin(), c.end());
    long long sum = 0;
    for (int i = 0; i < m && i < c.size(); i++) {
        sum += c[c.size() - i - 1];
    }
    return sum >= tot;
}

int main() {
    int total_cas;
    scanf("%d", &total_cas);
    for (int cas = 1; cas <= total_cas; cas++) {
        scanf("%d%d%d", &m, &tot, &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &x[i], &y[i], &z[i]);
        }
        long long l = 0, r = ~0ull >> 1;
        while (l < r) {
            long long mid = (l + r) / 2;
            if (can(mid)) r = mid;
            else l = mid + 1;
        }
        printf("Case #%d: %lld\n", cas, l);
    }
    return 0;
}
