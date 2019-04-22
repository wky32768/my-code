#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, t;
double raw[1200];
map<double, int> mp;
struct node {
    double x, y, z;
    int k;
    friend bool operator<(node a, node b) { return a.x < b.x; }
} a[230];
struct seg {
    int l, r, cnt;
    double len;
} tree[1200];
void build(int rt, int l, int r) {
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].cnt = 0;
    tree[rt].len = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
void change(int rt, int l, int r, int k) {
    if (l <= tree[rt].l && tree[rt].r <= r) {
        tree[rt].cnt += k;
        if (tree[rt].cnt) {
            tree[rt].len = raw[tree[rt].r + 1] - raw[tree[rt].l];
        } else {
            tree[rt].len = 0;
        }
    }
    if (tree[rt].l == tree[rt].r)
        return;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (l <= mid)
        change(rt << 1, l, r, k);
    if (r > mid)
        change(rt << 1 | 1, l, r, k);
    tree[rt].len = tree[rt].cnt ? raw[tree[rt].r + 1] - raw[tree[rt].l]
                                : tree[rt << 1].len + tree[rt << 1 | 1].len;
    return;
}
signed main() {
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            int k = i << 1;
            double y, z;
            cin >> a[k - 1].x >> y >> a[k].x >> z;
            raw[k - 1] = a[k - 1].y = a[k].y = y;
            raw[k] = a[k-1].z = a[k].z = z;
            a[k - 1].k = 1;
            a[k].k = -1;
        }
        n <<= 1;
        sort(raw + 1, raw + n + 1);
        int m = unique(raw + 1, raw + n + 1) - (raw + 1);
        for (int i = 1; i <= m; i++)
            mp[raw[i]] = i;
        sort(a + 1, a + n + 1);
        build(1, 1, m - 1);
        double ans = 0;
        for (int i = 1; i < n; i++) {
            int y = mp[a[i].y],
                z = mp[a[i].z] - 1; //这里要注意：对于区间的离散化只剩下了n-1个区间，所以在右端处理的时候要减一，线段树里加上长度的时候要加一（把区间的右边还原成点（如[1,2]的区间其实在点来看是[1,3]）
            change(1, y, z, a[i].k);
            ans += tree[1].len * (a[i + 1].x - a[i].x); //这一段小矩形的面积
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++t, ans);
    }
    return 0;
}