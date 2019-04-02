#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
const int N = 1200000;
int n, m, opt, x, y, a[N << 1], tree[1200000], mx_x, mx_y;
inline int read() {
    int x = 0;
    char ch = getchar();
    while (!(ch >= '0' && ch <= '9'))
        ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
inline void write(int x) {
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}
inline void clear(int x) {
    for (register int i = x; i <= mx_y; i += lowbit(i))
        tree[i] = 0;
}
inline int ask(int x) {
    int ans = 0;
    for (register int i = x; i; i -= lowbit(i))
        ans = max(ans, tree[i]);
    return ans;
}
inline void upd(int x, int C) {
    for (register int i = x; i <= mx_y; i += lowbit(i))
        tree[i] = max(tree[i], C);
}
struct node {
    int t, x, y;
    bool flag;
} q[N << 1];
inline bool cmp1(node a, node b) { return a.t < b.t; }
inline bool cmp2(node a, node b) {
    return (a.x == b.x) ? a.y < b.y : a.x < b.x;
}
/*
minni=1 (x−xi)+(y−yi) => (x+y)−max(xi+yi)其中xi、yi分别小于x、y
*/
inline void cdq(int l, int r) {
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    cdq(l, mid), cdq(mid + 1, r);
    int j = l;
    for (register int i = mid + 1; i <= r; i++) {
        if (q[i].flag)
            continue;
        for (; j <= mid && q[j].x <= q[i].x; j++)
            if (q[j].flag)
                upd(q[j].y, q[j].x + q[j].y);
        int now = ask(q[i].y);
        if (now)
            a[q[i].t] = min(a[q[i].t], q[i].x + q[i].y - now);
    }
    for (register int i = l; i < j; i++)
        if (q[i].flag)
            clear(q[i].y);
    inplace_merge(q + l, q + mid + 1, q + r + 1, cmp2); //归并排序
}
signed main() {
    scanf("%lld%lld", &n, &m);
    for (register int i = 1; i <= n; i++) {
        x = read(), y = read();
        x++, y++;
        q[i] = (node){i, x, y, 1};
        mx_x = max(mx_x, x), mx_y = max(mx_y, y);
    }
    while (m--) {
        opt = read(), x = read(), y = read();
        x++, y++;
        q[++n] = (node){n, x, y, opt & 1};
        mx_x = max(mx_x, x), mx_y = max(mx_y, y);
    }
    for (register int i = 1; i <= n; i++)
        a[i] = 0x3f3f3f3f;
    mx_x++, mx_y++;
    cdq(1, n);
    for (register int i = 1; i <= n; i++)
        q[i].x = mx_x - q[i].x;
    sort(q + 1, q + n + 1, cmp1);
    cdq(1, n);
    for (register int i = 1; i <= n; i++)
        q[i].x = mx_x - q[i].x;
    for (register int i = 1; i <= n; i++)
        q[i].y = mx_y - q[i].y;
    sort(q + 1, q + n + 1, cmp1);
    cdq(1, n);
    for (register int i = 1; i <= n; i++)
        q[i].y = mx_y - q[i].y;
    for (register int i = 1; i <= n; i++)
        q[i].x = mx_x - q[i].x, q[i].y = mx_y - q[i].y;
    sort(q + 1, q + n + 1, cmp1);
    cdq(1, n);
    for (register int i = 1; i <= n; i++)
        if (a[i] != 0x3f3f3f3f) {
            write(a[i]);
            puts("");
        }
    return 0;
}
