#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000;

int n;
int a[N];

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int k = lower_bound(a, a + n, a[i] + a[j]) - a - 1;
                if (k > j && k < n && a[i] + a[j] > a[k]) {
                    ans = max(ans, a[i] + a[j] + a[k]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
