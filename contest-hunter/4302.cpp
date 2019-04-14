#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x & (-x))
using namespace std;
int t[2300000], tree[2300000], a[1200000], b[1200000], n, m, l, r, x;
char ch;
void add(int x, int C) {
    for (; x <= n; x += lowbit(x))
        t[x] += C;
}
int tot(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x))
        ans += t[x];
    return ans;
}
void build(int l, int r, int rt) {
    if (l == r) {
        tree[rt] = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    tree[rt] = __gcd(tree[rt << 1], tree[rt << 1 | 1]);
    return;
}
void change(int which, int v, int l, int r, int rt) {
    if (l == r) {
        tree[rt] += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (which <= mid)
        change(which, v, l, mid, rt << 1);
    else
        change(which, v, mid + 1, r, rt << 1 | 1);
    tree[rt] = __gcd(tree[rt << 1], tree[rt << 1 | 1]);
}
int ask(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return abs(tree[rt]);
    int mid = (l + r) >> 1, ans = 0;
    if (L <= mid)
        ans = __gcd(ans, ask(L, R, l, mid, rt << 1));
    if (R > mid)
        ans = __gcd(ans, ask(L, R, mid + 1, r, rt << 1 | 1));
    return ans;
}
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        b[i] = a[i] - a[i - 1];
    }
    build(1, n, 1);
    while (m--) {
        cin >> ch >> l >> r;
        if (ch == 'Q') {
            int fen = a[l] + tot(l), val = l < r ? ask(l + 1, r, 1, n, 1) : 0;
            cout << __gcd(fen, val) << '\n';
        } else {
            cin >> x;
            change(l, x, 1, n, 1);
            if (r < n)
                change(r + 1, -x, 1, n, 1);
            add(l, x), add(r + 1, -x);
        }
    }
}