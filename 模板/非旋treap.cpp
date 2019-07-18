#include <bits/stdc++.h>
#define int long long
using namespace std;
int read() {
    int x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch))
        f |= (ch == '-'), ch = getchar();
    while (isdigit(ch))
        x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}
const int N = 1200000;
struct node {
    int ch[2], w, sz, rnd, same;
} t[N];
int ch[N], n, tot, opt, a, root, x, y, z;
void upd(int x) {
    t[x].sz = t[t[x].ch[0]].sz + t[t[x].ch[1]].sz + 1;
}
int New(int x) {
    t[++tot].sz = 1;
    t[tot].w = x;
    t[tot].rnd = rand();
    return tot;
}
int merge(int a, int b) {
    if (!a || !b)
        return a + b;
    if (t[a].rnd < t[b].rnd) {
        t[a].ch[1] = merge(t[a].ch[1], b);
        upd(a);
        return a;
    } else {
        t[b].ch[0] = merge(a, t[b].ch[0]);
        upd(b);
        return b;
    }
}
void split(int now, int k, int &x, int &y) {
    if (!now)
        x = y = 0;
    else {
        if (t[now].w <= k) {
            x = now;
            split(t[now].ch[1], k, t[now].ch[1], y); //让底下分出的左树的根节点来做右儿子
        } else {
            y = now;
            split(t[now].ch[0], k, x, t[now].ch[0]);
        }
        upd(now);
    }
}
int kth(int now, int k) {
    while (1) {
        if (k <= t[t[now].ch[0]].sz)
            now = t[now].ch[0];
        else if (k == t[t[now].ch[0]].sz + 1)
            return now;
        else {
            k -= (t[t[now].ch[0]].sz + 1);
            now = t[now].ch[1];
        }
    }
}
signed main() {
    srand((int)time(0));
    n = read();
    while (n--) {
        opt = read(), a = read();
        if (opt == 1) {
            split(root, a, x, y);
            root = merge(merge(x, New(a)), y);
        } else if (opt == 2) {
            split(root, a, x, z);
            split(x, a - 1, x, y); //把a这个数夹到树顶
            y = merge(t[y].ch[0], t[y].ch[1]);
            root = merge(merge(x, y), z);
        } else if (opt == 3) {
            split(root, a - 1, x, y);
            write(t[x].sz + 1);
            puts("");
            root = merge(x, y);
        } else if (opt == 4) {
            write(t[kth(root, a)].w);
            puts("");
        } else if (opt == 5) {
            split(root, a - 1, x, y);
            write(t[kth(x, t[x].sz)].w);
            puts("");
            merge(x, y);
        } else if (opt == 6) {
            split(root, a, x, y);
            write(t[kth(y, 1)].w);
            puts("");
            merge(x, y);
        }
    }
    return 0;
}