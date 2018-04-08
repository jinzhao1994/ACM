#include <cstdio>
#include <cstring>

// TODO: judge this code

bool a[100][100];  // true means not filled
int x1 = 1, x2 = 14, y1 = 1, y2 = 15;

void print(int x, int y) {
    printf("%d %d\n", x, y);
    fflush(stdout);
    /*
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            printf("%c", a[i][j] ? '.' : '#');
        }
        printf("\n");
    }
    printf("\n");
     */
}

void find_ans() {
    int n;
    scanf("%d", &n);
    memset(a, true, sizeof(a));
    for (int i = x1 + 1; i <= x2 - 1; i++) {
        for (int j = y1 + 1; j <= y2 - 1; j++) {
            while (a[i - 1][j - 1] ||
                   (j == y2 - 1 && (a[i - 1][j] || a[i - 1][j + 1])) ||
                   (i == x2 - 1 && (a[i + 1][j - 1] || a[i][j - 1])) ||
                   (j == y2 - 1 && i == x2 - 1 && (a[i + 1][j] || a[i + 1][j + 1] || a[i][j + 1] || a[i][j]))) {
                int x, y;
                print(i, j);
                scanf("%d%d", &x, &y);
                if (x == 0 && y == 0) return;
                if (x == -1 && y == -1) return;
                a[x][y] = false;
            }
        }
    }
}

int main() {
    int t, tt;
    scanf("%d", &tt);
    for (t = 1; t <= tt; t++) {
        find_ans();
    }
    return 0;
}
