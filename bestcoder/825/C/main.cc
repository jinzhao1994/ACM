#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 10001;

int n, k;
char s[N];

inline bool cmp(int x, int y) {
    return x > y;
}

int head_ones(char s[], int n) {
    for (int i = 0; i < n; i++) {
        if (s[i] != '1') {
            return i;
        }
    }
    return n;
}

int tail_ones(char s[], int n) {
    for (int i = 0; i < n; i++) {
        if (s[n - i - 1] != '1') {
            return i;
        }
    }
    return n;
}

int cal(int first, int last, int a[], int n, int k) {
    sort(a, a + n, cmp);
    // printf("first: %d, last: %d, a: ", first, last);
    // for (int i = 0; i < n && a[i] != 0; i++) printf("%d ", a[i]);
    // printf("\n");
    int ans = 0, sum = 0;
    for (int i = 0; i < n && k >= 0; i++, k -= 2) {
        if (k >= 0) {
            ans = max(ans, sum + first);
        }
        if (k >= 1) {
            ans = max(ans, sum + first + last);
            ans = max(ans, sum + a[i]);
        }
        if (k >= 2) {
            ans = max(ans, sum + last + a[i]);
        }
        if (k >= 3) {
            ans = max(ans, sum + first + last + a[i]);
        }
        sum += a[i];
    }
    return ans;
}

int cal() {
    static int a[N];
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    int first = head_ones(s, n);
    int last = tail_ones(s + first + 1, n - first - 1);
    int t = 0;
    for (int pos = first; pos < n - last - 1; pos += a[t - 1] + 1) {
        a[t++] = head_ones(s + pos, n - pos - last - 1);
    }
    return cal(first, last, a, n, k);
}

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        scanf("%s", s);
        printf("%d\n", cal());
    }
    return 0;
}
