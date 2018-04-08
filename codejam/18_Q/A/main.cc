#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 31;

int n;
char s[N];

int cal(char s[]) {
    int ans = 0, x = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'C') {
            x *= 2;
        } else {
            ans += x;
        }
    }
    return ans;
}

bool swap(char s[]) {
    for (int i = strlen(s) - 1; i > 0; i--) {
        if (s[i] == 'S' && s[i - 1] == 'C') {
            swap(s[i], s[i - 1]);
            return true;
        }
    }
    return false;
}

int main() {
    int t, tt;
    scanf("%d", &tt);
    for (t = 1; t <= tt; t++) {
        scanf("%d%s", &n, s);
        int ans = 0;
        while (cal(s) > n) {
            ans++;
            if (!swap(s)) {
                ans = -1;
                break;
            }
        }
        if (ans != -1) {
            printf("Case #%d: %d\n", t, ans);
        } else {
            printf("Case #%d: IMPOSSIBLE\n", t);
        }
    }
    return 0;
}
