#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

inline int abs(int x) {
    if (x >= 0) {
        return x;
    }
    return -x;
}

const int N = 100;

int n;
int a[N];
char s[N][N];

int cal() {
    if (a[0] == 0 || a[n - 1] == 0) {
        return -1;
    }
    memset(s, '.', N * N);
    int sum = 0, ans = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            continue;
        }
        for (int j = 1; i - j >= sum; j++) {
            s[j][i - j] = '\\';
            ans = max(ans, j + 1);
        }
        sum += a[i];
        for (int j = 1; i + j < sum; j++) {
            s[j][i + j] = '/';
            ans = max(ans, j + 1);
        }
    }
    return ans;
}

int main() {
    int total_cas;
    scanf("%d", &total_cas);
    for (int cas = 1; cas <= total_cas; cas++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int ans = cal();
        if (ans == -1) {
            printf("Case #%d: IMPOSSIBLE\n", cas);
        } else {
            printf("Case #%d: %d\n", cas, ans);
            for (int i = ans - 1; i >= 0; i--) {
                for (int j = 0; j < n; j++) {
                    printf("%c", s[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
