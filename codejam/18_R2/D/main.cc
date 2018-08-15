#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 20;
const int DIR[4][2] = {{0,  1},
                       {0,  -1},
                       {1,  0},
                       {-1, 0}};

char a[N][N];
bool b[N][N];
int x[N * N], y[N * N], p, q;

bool in(int i, int j, int imin, int imax, int jmin, int jmax) {
    return i >= imin && i <= imax && j >= jmin && j <= jmax;
}

void put(int i, int j) {
    b[i][j] = true;
    x[q] = i;
    y[q] = j;
    q++;
}

void pick(int &i, int &j) {
    i = x[p];
    j = y[p];
    p++;
}

int bfs(int si, int sj, int imin, int imax, int jmin, int jmax) {
    if (!in(si, sj, imin, imax, jmin, jmax)) {
        return 0;
    }
    p = q = 0;
    put(si, sj);
    while (p != q) {
        int i, j;
        pick(i, j);
        for (int k = 0; k < 4; k++) {
            int ii = i + DIR[k][0], jj = j + DIR[k][1];
            if (in(ii, jj, imin, imax, jmin, jmax)
                && !b[ii][jj]
                && a[ii][jj] == a[si][sj]) {
                put(ii, jj);
            }
        }
    }
    return q;
}

int find(int imin, int imax, int jmin, int jmax, char c) {
    for (int i = imin; i <= imax; i++) {
        for (int j = jmin; j <= jmax; j++) {
            b[i][j] = false;
        }
    }
    int ans = 0;
    for (int i = imin; i <= imax; i++) {
        for (int j = jmin; j <= jmax; j++) {
            if (a[i][j] == c && !b[i][j]) {
                ans = max(ans, bfs(i, j, imin, imax, jmin, jmax));
            }
        }
    }
}

int case1(int n, int m) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'W') {
                flag = true;
            }
        }
    }
    if (!flag) {
        return 0;
    }
    return find(0, n - 1, 0, m - 1, 'W');
}

int case2(int n, int m) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'B') {
                flag = true;
            }
        }
    }
    if (!flag) {
        return 0;
    }
    return find(0, n - 1, 0, m - 1, 'B');
}

int case3(int n, int m) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
    }
}

int case4(int n, int m) {
}


int main() {
    int total_cas;
    scanf("%d", &total_cas);
    for (int cas = 1; cas <= total_cas; cas++) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %c", &a[i][j]);
            }
        }
        int ans = 0;
        ans = max(ans, case1(n, m));
        ans = max(ans, case2(n, m));
        ans = max(ans, case3(n, m));
        ans = max(ans, case4(n, m));
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
