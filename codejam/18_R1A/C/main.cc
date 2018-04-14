#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100;
const double eps = 1e-9;

struct Interval {
    double l, r;

    Interval(double l, double r) : l(l), r(r) {}
};

inline bool eq(double x, double y) {
    return x - y < eps && y - x < eps;
}

inline bool cmp(const Interval &x, const Interval &y) {
    if (eq(x.l, y.l)) return x.r > y.r;
    return x.l < y.l;
}

int n;
double x[N], y[N], p;
vector <Interval> a, b;

int main() {
    int total_cas;
    scanf("%d", &total_cas);
    for (int cas = 1; cas <= total_cas; cas++) {
        scanf("%d%lf", &n, &p);
        double sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &x[i], &y[i]);
            sum += x[i] + x[i] + y[i] + y[i];
        }
        a.clear();
        a.push_back(Interval(sum, sum));
        for (int i = 0; i < n; i++) {
            double t1 = min(x[i], y[i]) * 2, t2 = sqrt(x[i] * x[i] + y[i] * y[i]) * 2;
            b.clear();
            for (Interval c : a) {
                b.push_back(c);
                b.push_back(Interval(c.l + t1, c.r + t2));
            }
            sort(b.begin(), b.end(), cmp);
            // printf("cs b: %lu\n", b.size());
            // for (Interval c: b) printf("cs -- %.8f %.8f\n", c.l, c.r);
            a.clear();
            Interval cur = b[0];
            for (Interval c: b) {
                if (c.l <= cur.r + eps) {
                    cur.r = max(cur.r, c.r);
                } else {
                    a.push_back(cur);
                    cur = c;
                }
            }
            a.push_back(cur);
            // printf("cs a: %lu\n", a.size());
            // for (Interval c: a) printf("cs == %.8f %.8f\n", c.l, c.r);
            // printf("\n");  // "cs
        }
        double ans = sum;
        for (Interval c: a) {
            if (c.l <= p + eps) {
                ans = max(ans, min(p, c.r));
            }
        }
        printf("Case #%d: %.8f\n", cas, ans);
    }
    return 0;
}
