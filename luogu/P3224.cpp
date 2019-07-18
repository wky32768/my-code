#include <bits/stdc++.h>
#define For(i, a, b) for (register int i = a; i <= b; i++)
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
const int M = 1800000;
struct node {
    int ls, rs, w, sz;
} t[M];
const int N = 120000;
int n, m, a[N], fa[N], x, y, tot, q, root[N], id[N];
char ch;
int find(int x) {
    if (fa[x] == x)
        return fa[x];
    else
        return fa[x] = find(fa[x]);
}
void insert(int &now, int l, int r, int w) {
    if (!now)
        now = ++tot;
    if (l == r) {
        t[now].w = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (w <= mid)
        insert(t[now].ls, l, mid, w);
    else
        insert(t[now].rs, mid + 1, r, w);
    t[now].w = t[t[now].ls].w + t[t[now].rs].w;
}
int query(int now, int l, int r, int rnk) {
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    if (t[t[now].ls].w >= rnk)
        return query(t[now].ls, l, mid, rnk);
    else
        return query(t[now].rs, mid + 1, r, rnk - t[t[now].ls].w);
}
int merge(int x, int y) { //线段树的合并
    if (!x)
        return y;
    if (!y)
        return x;
    t[x].ls = merge(t[x].ls, t[y].ls);
    t[x].rs = merge(t[x].rs, t[y].rs);
    t[x].w = t[t[x].ls].w + t[t[x].rs].w;
    return x;                                                                                                    
}
signed main() {
    n = read(), m = read();
    For(i, 1, n) {
        a[i] = read();
        fa[i] = i;
    }
    while (m--) {
        x = read(), y = read();
        int xx = find(x), yy = find(y);
        fa[xx] = yy;
    }
    For(i, 1, n) {
        insert(root[find(i)], 1, n, a[i]);
        id[a[i]] = i;
    }
    q = read();
    while (q--) {
        cin >> ch;
        x = read(), y = read();
        if (ch == 'Q') {
            int which = find(x);
            if (t[root[which]].w < y) {
                puts("-1");
            } else {
                write(id[query(root[which], 1, n, y)]); //线段树构造是用值域的，所以找到答案和要变回去
                puts("");
            }
        } else {
            int xx = find(x), yy = find(y);
            if (xx != yy) {
                fa[xx] = yy;
                root[y] = merge(root[yy], root[xx]);
            }
        }
    }
    return 0;
}
