#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 101;

int n, m, p, q;
int x[N], y1[N], y2[N];
char c[N][N];

bool try_split_row(int tot) {
    int cnt = 0, k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '@') cnt++;
        }
        if (cnt > tot) {
            return false;
        }
        if (cnt == tot) {
            x[k++] = i;
            cnt = 0;
        }
    }
    // for (int i = 0; i <= p; i++) printf("cs x[%d]=%d\n", i, x[i]);
    return true;
}

bool try_split_col(char c[][N], int n, int tot) {
    int cnt = 0, k = 0, right = -1;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (c[i][j] == '@') cnt++;
        }
        if (cnt > tot) {
            return false;
        }
        if (cnt != 0) {
            y2[k - 1] = min(y2[k - 1], right);
        }
        if (cnt == tot) {
            y1[k] = max(y1[k], j);
            k++;
            cnt = 0;
        }
        if (cnt == 0 && k != 0) {
            right = j;
        }
    }
    // printf("cs ===\n");
    // for (int j = 0; j <= q; j++) printf("cs y1[%d]=%d y2[%d]=%d\n", j, y1[j], j, y2[j]);
    return true;
}

bool find_ans() {
    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '@') tot++;
        }
    }
    if (tot % ((p + 1) * (q + 1)) != 0) {
        return false;
    }
    int each = tot / ((p + 1) * (q + 1));
    if (!try_split_row(each * (q + 1))) return false;
    for (int j = 0; j <= q; j++) {
        y1[j] = 0;
        y2[j] = m - 1;
    }
    if (!try_split_col(c, x[0] + 1, each)) return false;
    for (int i = 1; i <= p; i++) {
        if (!try_split_col(c + x[i - 1] + 1, x[i] - x[i - 1], each)) return false;
    }
    for (int j = 0; j <= q; j++) {
        if (y1[j] > y2[j]) return false;
    }
    return true;
}

int main() {
    int total_cas;
    scanf("%d", &total_cas);
    for (int cas = 1; cas <= total_cas; cas++) {
        scanf("%d%d%d%d", &n, &m, &p, &q);
        for (int i = 0; i < n; i++) {
            scanf("%s", c[i]);
        }
        if (find_ans()) {
            printf("Case #%d: POSSIBLE\n", cas);
        } else {
            printf("Case #%d: IMPOSSIBLE\n", cas);
        }
    }
    return 0;
}
