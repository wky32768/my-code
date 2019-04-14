#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1200000;
int n, m, x, y, z, head1[N], head2[N], cnt1, cnt2, w[N], ans, f[N], d[N];
bool vis[N];
struct node {
    int next, to;
} sxd1[N << 1], sxd2[N << 1];
void add1(int u, int v) {
    sxd1[++cnt1].next = head1[u];
    sxd1[cnt1].to = v;
    head1[u] = cnt1;
}
void add2(int u, int v) {
    sxd2[++cnt2].next = head2[u];
    sxd2[cnt2].to = v;
    head2[u] = cnt2;
}
queue<int> q;
void spfa1() {
    memset(vis,0,sizeof vis);
    memset(d, 0x3f, sizeof d);
    while(!q.empty()) q.pop();
    q.push(1);
    while (!q.empty()) {
        int at = q.front();
        q.pop();
        vis[at] = 0;
        for (int i = head1[at]; i; i = sxd1[i].next)
            if (d[sxd1[i].to] > min(d[at], w[sxd1[i].to])) {
                d[sxd1[i].to] = min(d[at], w[sxd1[i].to]);
                if (!vis[sxd1[i].to]) {
                    q.push(sxd1[i].to);
                    vis[sxd1[i].to]=1;
                }
            }
    }
}
void spfa2() {
    memset(vis,0,sizeof vis);
    memset(f, 0, sizeof d);
    while(!q.empty()) q.pop();
    f[n] = 0;
    q.push(n);
    while (!q.empty()) {
        int at = q.front();
        q.pop();
        vis[at] = 0;
        for (int i = head2[at]; i; i = sxd2[i].next)
            if (f[sxd2[i].to] < max(f[at], w[sxd2[i].to])) {
                f[sxd2[i].to] = max(f[at], w[sxd2[i].to]);
                if (!vis[sxd2[i].to])
                    q.push(sxd2[i].to);
            }
    }
}
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &w[i]);
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &x, &y, &z);
        if (z == 1) {
            add1(x, y);
            add2(y, x);
        } else {
            add1(x, y);
            add1(y, x);
            add2(y, x);
            add2(x, y);
        }
    }
    spfa1();
    spfa2();
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i] - d[i]);
    cout << ans << '\n';
    return 0;
}