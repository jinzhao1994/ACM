#include <cstdio>
#include <utility>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 501;

typedef pair<int, pair<int, int>> X;

X x(int i, int n, int m) {
    return make_pair(i, make_pair(n, m));
}

struct HashX {
    std::size_t operator()(X x) const {
        return x.first * N * N + x.second.first * N + x.second.second;
    }
};

unordered_map<X, int, HashX> cache;

inline int get_sqrt(int n) {
    int sum = 0;
    for (int j = 0; j < 40; j++) {
        sum += j;
        if (sum > n) {
            return j;
        }
    }
    return 0;
}

int minh(int i, int n, int m) {
    if (i == 0) {
        return get_sqrt(m);
    }
    return min(n / i, get_sqrt(m));
}

int maxh(int i, int n, int m) {
    if (i == 0) {
        return n + m;
    }
    return n / i;
}

int find(int i, int n, int m) {
    if (i > n) return 0;
    auto it = cache.find(x(i, n, m));
    if (it != cache.end()) {
        return it->second;
    }
    int ans = minh(i, n, m);
    // 40 is enough for n, m <= 500
    for (int j = 0; j < 40; j++) {
        int subn = j * i, subm = (j - 1) * j / 2;
        if (subn > n || subm > m) {
            break;
        }
        if (ans >= j + maxh(i + 1, n - subn, m - subm)) {
            continue;
        }
        ans = max(ans, j + find(i + 1, n - subn, m - subm));
    }
    cache[x(i, n, m)] = ans;
    // printf("%d %d %d = %d\n", i, n, m, ans);
    return ans;
}

int main() {
    int total_cas;
    scanf("%d", &total_cas);
    for (int cas = 1; cas <= total_cas; cas++) {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("Case #%d: %d\n", cas, find(0, n, m) - 1);
    }
    return 0;
}
