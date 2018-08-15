#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100 * 200 * 2 + 1;
const int M = 100 * 200 * 2 + 100 * 100;
const int INF = ~0u >> 2;

struct NetWorkFlow {
    struct Edge {
        int t, f;
        Edge *ne, *p;

        Edge *clear(int tt, int ff, Edge *nee) {
            t = tt;
            f = ff;
            ne = nee;
            return this;
        }
    };

    Edge b[M * 2], *p, *fe[N], *cur[N];
    int n, s, t, h[N], vh[N];

    void clear(int nn, int ss, int tt) {
        n = nn;
        s = ss;
        t = tt;
        for (int i = 0; i < n; i++) fe[i] = NULL;
        p = b;
    }

    void putedge(int x, int y, int f) {
        fe[x] = (p++)->clear(y, f, fe[x]);
        fe[y] = (p++)->clear(x, 0, fe[y]);
        fe[x]->p = fe[y];
        fe[y]->p = fe[x];
    }

    int aug(int i, int f) {
        if (i == t) return f;
        int minh = n;
        Edge *seg = cur[i], *&j = cur[i];
        do {
            if (j->f) {
                if (h[j->t] + 1 == h[i]) {
                    int tmp = aug(j->t, min(j->f, f));
                    if (tmp) {
                        j->f -= tmp;
                        j->p->f += tmp;
                        return tmp;
                    }
                }
                minh = min(minh, h[j->t] + 1);
                if (h[s] == n) return 0;
            }
            j = j->ne;
            if (j == NULL) j = fe[i];
        } while (j != seg);
        if (!--vh[h[i]]) h[s] = n;
        else ++vh[h[i] = minh];
        return 0;
    }

    int flow() {
        if (fe[s] == NULL) return 0;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            cur[i] = fe[i];
            h[i] = vh[i] = 0;
        }
        vh[0] = n;
        while (h[s] < n) ans += aug(s, INF);
        return ans;
    }
};

NetWorkFlow c;

int main() {
    int total_cas;
    scanf("%d", &total_cas);
    for (int cas = 1; cas <= total_cas; cas++) {
        int n, x;
        scanf("%d", &n);
        int m = n * n * 2, s = m * 2, t = s + 1;
        c.clear(m * 2 + 2, s, t);
        for (int i = 0; i < m; i++) {
            c.putedge(s, i, 1);
            c.putedge(i + m, t, 1);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &x);
                if (x > 0) {
                    x = x - 1;
                } else {
                    x = -x + n - 1;
                }
                c.putedge(i * n * 2 + x, m + j * n * 2 + x, 1);
            }
        }
        printf("Case #%d: %d\n", cas, n * n - c.flow());
    }
    return 0;
}
