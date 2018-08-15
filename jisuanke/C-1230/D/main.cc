#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MOD = 323232323;
const int N = 100000;

inline void mul(int &x, int y) {
    x = (long long) x * y % MOD;
}

inline int pow(int x, int n) {
    int ans = 1;
    while (n) {
        if (n % 2 == 1) mul(ans, x);
        mul(x, x);
        n = n / 2;
    }
    return ans;
}

inline void div(int &x, int y) {
    return mul(x, pow(y, MOD - 2));
}

inline void add(int &x, int y) {
    x = x + y;
    if (x >= MOD) {
        x -= MOD;
    }
}

inline void sub(int &x, int y) {
    x = x - y + MOD;
    if (x >= MOD) {
        x -= MOD;
    }
}

int id;

struct Point {
    int x[2];

    friend bool operator<(const Point &a, const Point &b) {
        return a.x[id] < b.x[id];
    }

    friend bool operator<=(const Point &a, const Point &b) {
        return a.x[id] <= b.x[id];
    }
};

inline int intersection(int a, int b, int c, int d) {
    return max(0, min(b, d) - max(a, c) + 1);
}

inline long long intersection(Point a, Point b, Point c, Point d) {
    return (long long) intersection(a.x[0], b.x[0], c.x[0], d.x[0])
           * intersection(a.x[1], b.x[1], c.x[1], d.x[1]);
}

struct Node {
    Point l, r, x;
    int p, v, plazy, vlazy;
};

Point b[N];
Node c[N * 2];

void updateArea(int x, int y) {
    c[x].l.x[0] = min(c[x].l.x[0], c[y].l.x[0]);
    c[x].l.x[1] = min(c[x].l.x[1], c[y].l.x[1]);
    c[x].r.x[0] = max(c[x].r.x[0], c[y].r.x[0]);
    c[x].r.x[1] = max(c[x].r.x[1], c[y].r.x[1]);
}

void down(int d, int l, int r) {
    int t = (l + r) / 2, ls = d * 2, rs = ls + 1;
    if (l < t) {
        mul(c[ls].plazy, c[d].plazy);
        add(c[ls].vlazy, c[d].vlazy);
    }
    if (t + 1 < r) {
        mul(c[rs].plazy, c[d].plazy);
        add(c[rs].vlazy, c[d].vlazy);
    }
    mul(c[d].p, c[d].plazy);
    add(c[d].v, c[d].vlazy);
    c[d].plazy = 1;
    c[d].vlazy = 0;
}

void build(int d, int l, int r, int o) {
    if (l >= r) {
        return false;
    }
    int t = (l + r) / 2, ls = d * 2, rs = ls + 1;
    id = o;
    nth_element(b + l, b + t, b + r);
    c[d].l = c[d].r = c[d].x = b[t];
    c[d].p = c[d].plazy = 1;
    c[d].v = c[d].vlazy = 0;
    if (build(ls, l, t, o ^ 1)) {
        updateArea(d, ls);
    }
    if (build(rs, t + 1, r, o ^ 1)) {
        updateArea(d, rs);
    }
    return true;
}

void set(int d, int l, int r, Point ll, Point rr, int p, int q) {
    if (l >= r) {
        return;
    }
    down(d, l, r);
    if (c[d].l.x[0] >= ll.x[0] && c[d].l.x[1] >= ll.x[1]
        && c[d].r.x[0] <= rr.x[0] && c[d].r.x[1] <= rr.x[1]) {
        add(c[d].vlazy, mul(q, c[d].p));
        mul(c[d].plazy, p);
    } else {
        int t = (l + r) / 2, ls = d * 2, rs = ls + 1;
        if (intersection(c[ls].l, c[ls].r, ll, rr) > 0) {
            set(ls, l, t, ll, rr, p, q);
        }
        if (intersection(c[rs].l, c[rs].r, ll, rr) > 0) {
            set(rs, t + 1, r, ll, rr, p, q);
        }
    }
}

pair<int, int> get(int d, int l, int r, Point i) {
    if (l >= r) {
        return make_pair<int, int>(1, 0);
    }
    down(d, l, r);
    if (c[d].x.x[0] == i.x[0] && c[d].x[1] == i.x[1]) {
        return make_pair<int, int>(c[d].p, c[d].v);
    }
    int t = (l + r) / 2, ls = d * 2, rs = ls + 1;
    if (intersection(c[ls].l, c[ls.r], i, i) > 0) {
        return get(ls, l, t, i);
    }
    if (intersection(c[rs].l, c[rs.r], i, i) > 0) {
        return get(rs, t + 1, r, i);
    }
};


vector<int> solve(vector <Point> &l, vector <Point> &r, vector<int> &y, vector<int> &yP, vector<int> &yQ,
                  vector<int> &qL, vector<int> &qR, vector <Point> &qX) {
    const int m = y.size();
    const int n = qX.size();
    vector<int> d(n + m + n);
    vector<int> ansLong(n), ansShort(n), ansShortP(n), ans(n);
    for (int i = 0; i < n + m + n; i++) {
        d[i] = i;
    }
    getY = [&](int i) -> int {
        if (i < n) {
            return qL[i];
        }
        if (i < n + m) {
            return y[i - n];
        }
        return qR[i - n - m];
    };
    sort(d.begin(), d.end(), [&](int i, int j) {
        if (getY(i) != getY(j)) {
            return getY(i) < getY(j);
        }
        return i < j;
    });
    for (int i = 0; i < n; i++) {
        b[i] = qX[i];
    }
    build(1, 0, n, 0);
    for (int i = 0; i < d.size(); i++) {
        if (d[i] < n) {
            int t = d[i];
            pair<int, int> tmp = get(1, 0, n, qX);
            ansShortP[t] = tmp.first;
            ansShort[t] = tmp.second;
        } else if (d[i] < n + m) {
            int t = d[i] - n;
            set(1, 0, n, l[t], r[t], yP[t], yQ[t]);
        } else {
            int t = d[i] - n - m;
            pair<int, int> tmp = get(1, 0, n, qX);
            ansLong[t] = tmp.second;
        }
    };
    for (int i = 0; i < n; i++) {
        ans = ansLong;
        sub(ans, ansShort);
        div(ans, ansShortP);
    }
    return ans;
}

int main() {
    int n, m, q;
    while (scanf("%d%d%d", &n, &m, &q) != EOF) {
        vector<int> l, r, y, p, q;
        vector<int> qx, ql, qr;
        vector<int> d;
        for (int i = 0; i < q; i++) {
            char c;
            scanf(" %c", &c);
        }
    }
    return 0;
}
