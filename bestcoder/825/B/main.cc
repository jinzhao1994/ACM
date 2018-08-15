#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 400001;
const int M = 150001;

struct Node {
    int val, pos;
};

struct List {
    int head, tail;
};

Node a[N];
List b[M];
int t, n, q;

void first_node(int i, int v) {
    a[t].val = v;
    a[t].pos = 0;
    b[i].head = b[i].tail = t++;
}

void push_head(int i, int v) {
    if (b[i].head == 0) {
        first_node(i, v);
    } else {
        a[t].val = v;
        a[t].pos = b[i].head;
        a[b[i].head].pos ^= t;
        b[i].head = t++;
    }
}

void push_tail(int i, int v) {
    if (b[i].head == 0) {
        first_node(i, v);
    } else {
        a[t].val = v;
        a[t].pos = b[i].tail;
        a[b[i].tail].pos ^= t;
        b[i].tail = t++;
    }
}

int head(int i) {
    if (b[i].head == 0) {
        return -1;
    }
    int old_head = b[i].head;
    if (a[old_head].pos != 0) {
        b[i].head = a[old_head].pos;
        a[a[old_head].pos].pos ^= old_head;
    } else {
        b[i].head = b[i].tail = 0;
    }
    return a[old_head].val;
}

int tail(int i) {
    if (b[i].tail == 0) {
        return -1;
    }
    int old_tail = b[i].tail;
    if (a[old_tail].pos != 0) {
        b[i].tail = a[old_tail].pos;
        a[a[old_tail].pos].pos ^= old_tail;
    } else {
        b[i].head = b[i].tail = 0;
    }
    return a[old_tail].val;
}

void link(int i, int j) {
    if (b[j].head == 0) {
    } else if (b[i].head == 0) {
        b[i].head = b[j].head;
        b[i].tail = b[j].tail;
        b[j].head = b[j].tail = 0;
    } else {
        a[b[i].tail].pos ^= b[j].head;
        a[b[j].head].pos ^= b[i].tail;
        b[i].tail = b[j].tail;
        b[j].head = b[j].tail = 0;
    }
}

void reverse(int i) {
    swap(b[i].head, b[i].tail);
}

inline int in() {
    char c = getchar();
    int ans = 0;
    while (c < '0' || c > '9') {
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}

void print(int i) {
    printf("List #%d: ", i);
    if (b[i].head == 0) {
        printf("\n");
        return;
    }
    int last = 0, cur = b[i].head, next = a[cur].pos ^ last;
    while (cur != 0) {
        printf("%d ", a[cur].val);
        last = cur;
        cur = next;
        next = a[cur].pos ^ last;
    }
    printf("\n");
}

void print() {
    for (int i = 1; i <= n; i++) {
        print(i);
    }
}

int main() {
    while (scanf("%d%d", &n, &q) != EOF) {
        // printf("--- %d %d\n", n, q);
        t = 1;
        for (int i = 1; i <= n; i++) {
            b[i].head = b[i].tail = 0;
        }
        for (int i = 0; i < q; i++) {
            int c = in();
            if (c == 1) {
                int u = in(), w = in(), val = in();
                // printf("--- %d %d %d %d\n", c, u, w, val);
                if (w == 0) {
                    push_head(u, val);
                } else {
                    push_tail(u, val);
                }
            } else if (c == 2) {
                int u = in(), w = in();
                // printf("--- %d %d %d\n", c, u, w);
                if (w == 0) {
                    printf("%d\n", head(u));
                } else {
                    printf("%d\n", tail(u));
                }
            } else if (c == 3) {
                int u = in(), v = in(), w = in();
                // printf("--- %d %d %d %d\n", c, u, v, w);
                if (w == 1) {
                    reverse(v);
                }
                link(u, v);
            }
            // print();
        }
    }
    return 0;
}
