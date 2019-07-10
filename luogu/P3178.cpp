#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
#define gc getchar
#define pc putchar
using namespace std;
const int N = 300005;
const int M = 10000005;
int read() {
    int x = 0, f = 0;
    char ch = gc();
    while (!isdigit(ch))
        f |= (ch == '-'), ch = gc();
    while (isdigit(ch))
        x = x * 10 + ch - '0', ch = gc();
    return f ? -x : x;
}
void write(int x) {
    if (x < 0)
        pc('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    pc(x % 10 + '0');
}
vector<int> sxd[N];
int n, m, a[N], opt, x, y, w[N], at1[N], at2[N], zf[N], f[N];
int tree[M], add[M], xu[M];
void dfs(int x, int fa) {
    xu[++xu[0]] = x;
    at1[x] = xu[0];
    w[xu[0]] = a[x];
    f[xu[0]] = 1;
    For(i, 0, (int)sxd[x].size() - 1) if (sxd[x][i] != fa) dfs(sxd[x][i], x);
    xu[++xu[0]] = x;
    w[xu[0]] = -a[x];
    at2[x] = xu[0];
    f[xu[0]] = -1;
}
void build(int rt, int l, int r) {
    if (l == r) {
        tree[rt] = w[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}
void pushdown(int rt, int l, int mid, int r) {
    if (add[rt]) {
        add[rt << 1] += add[rt], add[rt << 1 | 1] += add[rt];
        tree[rt << 1] += add[rt] * (zf[mid] - zf[l - 1]), tree[rt << 1 | 1] += add[rt] * (zf[r] - zf[mid]);
        add[rt] = 0;
    }
}
void change(int which, int C, int l, int r, int rt) {
    tree[rt] += C;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    pushdown(rt, l, mid, r);
    if (which <= mid)
        change(which, C, l, mid, rt << 1);
    else
        change(which, C, mid + 1, r, rt << 1 | 1);
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}
void change_more(int L, int R, int C, int l, int r, int rt) {
    if (L <= l && r <= R) {
        add[rt] += C;
        tree[rt] += C * (zf[r] - zf[l - 1]);
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(rt, l, mid, r);
    if (L <= mid)
        change_more(L, R, C, l, mid, rt << 1);
    if (R > mid)
        change_more(L, R, C, mid + 1, r, rt << 1 | 1);
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}
int he(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return tree[rt];
    int mid = (l + r) >> 1, tot = 0;
    pushdown(rt, l, mid, r);
    if (L <= mid)
        tot += he(L, R, l, mid, rt << 1);
    if (R > mid)
        tot += he(L, R, mid + 1, r, rt << 1 | 1);
    return tot;
}
signed main() {
    n = read(), m = read();
    For(i, 1, n) a[i] = read();
    For(i, 1, n - 1) {
        x = read(), y = read();
        sxd[x].push_back(y);
        sxd[y].push_back(x);
    }
    dfs(1, 0);
    For(i, 1, n * 2) zf[i] = zf[i - 1] + ((f[i] > 0) ? 1 : -1);
    build(1, 1, n * 2);
    while (m--) {
        opt = read();
        if (opt == 1) {
            x = read(), y = read();
            change(at1[x], y, 1, n * 2, 1);
            change(at2[x], -y, 1, n * 2, 1);
        } else if (opt == 2) {
            x = read(), y = read();
            change_more(at1[x], at2[x], y, 1, n * 2, 1);
        } else if (opt == 3) {
            x = read();
            write(he(1, at1[x], 1, n * 2, 1));
            puts("");
        }
    }
    return 0;
}
