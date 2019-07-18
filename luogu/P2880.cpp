#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1200000;
int tree[N], n, m, a[N], mx[N], mn[N], x, y;
void build(int rt, int l, int r) {
    if (l == r) {
        tree[rt] = mx[rt] = mn[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
    mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
}
int da(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return mx[rt];
    int mid = (l + r) >> 1, mx = 0;
    if (L <= mid)
        mx = max(mx, da(L, R, l, mid, rt << 1));
    if (R > mid)
        mx = max(mx, da(L, R, mid + 1, r, rt << 1 | 1));
    return mx;
}
int xiao(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return mn[rt];
    int mid = (l + r) >> 1, mn = 0x3f3f3f3f;
    if (L <= mid)
        mn = min(mn, xiao(L, R, l, mid, rt << 1));
    if (R > mid)
        mn = min(mn, xiao(L, R, mid + 1, r, rt << 1 | 1));
    return mn;
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while (m--) {
        cin >> x >> y;
        cout << da(x, y, 1, n, 1) - xiao(x, y, 1, n, 1) << '\n';
    }
    return 0;
}