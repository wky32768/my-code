#include <bits/stdc++.h>
#define int long long
#define rg register
using namespace std;
const int N = 520000;
int read() {
    int x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) {
        f |= (ch == '-');
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f ? -x : x;
}
void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}
int n, m, a[N], opt, x, y;
struct segment {
    int sum, w, l, r;
} tree[N << 2];
void up(int x) {
    tree[x].sum = tree[x << 1].sum + tree[x << 1 | 1].sum;
    tree[x].l = max(tree[x<<1].l, tree[x << 1].sum + tree[x << 1 | 1].l);
    tree[x].r = max(tree[x<<1|1].r, tree[x << 1].r + tree[x << 1 | 1].sum);
    tree[x].w = max(max(tree[x << 1].w, tree[x << 1 | 1].w),tree[x << 1].r + tree[x << 1 | 1].l);
}
void build(int rt, int l, int r) {
    if (l == r) {
        tree[rt].sum = tree[rt].w = tree[rt].l = tree[rt].r = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    up(rt);
}
void upd(int x, int C, int l, int r, int rt) {
    if (l == r) {
        tree[rt].sum = tree[rt].w = tree[rt].l = tree[rt].r = C;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        upd(x, C, l, mid, rt << 1);
    else
        upd(x, C, mid + 1, r, rt << 1 | 1);
    up(rt);
}
segment ask(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return tree[rt];
    segment ans, ll, rr;
    ll.sum = ll.l = ll.r = ll.w = rr.sum = rr.l = rr.r = rr.w = -0x3f3f3f3f3f;
    ans.sum = 0;
    int mid = (l + r) >> 1;
    if (L <= mid) {
        ll = ask(L, R, l, mid, rt << 1);
        ans.sum += ll.sum;
    }
    if (R > mid) {
        rr = ask(L, R, mid + 1, r, rt << 1 | 1);
        ans.sum += rr.sum;
    }
    ans.w = max(max(ll.w, rr.w), ll.r + rr.l);
    ans.l = max(ll.l, ll.sum + rr.l);
    ans.r = max(rr.r, ll.r + rr.sum);
    if (L > mid)
        ans.l = max(ans.l, rr.l);
    if (R <= mid)
        ans.r = max(ans.r, ll.r);
    return ans;
}
signed main() {
    n = read(), m = read();
    for (rg int i = 1; i <= n; i++)
        a[i] = read();
    build(1, 1, n);
    while (m--) {
        opt = read(), x = read(), y = read();
        if (opt == 1) {
            if(x>y) swap(x,y);
            write(ask(x, y, 1, n, 1).w);
            puts("");
        } else
            upd(x, y, 1, n, 1);
    }
}