/*
换根法，用于要求不同的根计算的同一种情况，先跑一次算出所有的状态，然后再通过dfs转移
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int t, n, m, head[600000], du[600000], d[600000], f[600000], cnt, x, y, z, mx;
struct node {
    int next, to, w;
} sxd[1200000];
void add(int u, int v, int w) {
    sxd[++cnt].next = head[u];
    sxd[cnt].to = v;
    sxd[cnt].w = w;
    head[u] = cnt;
}
void first_search(int at, int fa) {
    for (int i = head[at]; i; i = sxd[i].next) {
        if (sxd[i].to == fa)
            continue;
        first_search(sxd[i].to, at);
        if (du[sxd[i].to] == 1)
            d[at] += sxd[i].w;
        else
            d[at] += min(d[sxd[i].to], sxd[i].w);
    }
}
void dfs(int at, int fa) {
    for (int i = head[at]; i; i = sxd[i].next) {
        if (sxd[i].to == fa)
            continue;
        if (du[at] == 1)
            f[sxd[i].to] = d[sxd[i].to] + sxd[i].w;
        else
            f[sxd[i].to] = d[sxd[i].to] + min(sxd[i].w, f[at] - min(d[sxd[i].to], sxd[i].w));
        dfs(sxd[i].to, at);
    }
}
signed main() {
    scanf("%d", &t);
    while (t--) {
        memset(head, 0, sizeof head);
        memset(f, 0, sizeof f);
        memset(d, 0, sizeof d);
        memset(du, 0, sizeof du);
        cnt = 0;
        memset(sxd, 0, sizeof sxd);
        scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
            add(y, x, z);
            du[x]++, du[y]++;
        }
        first_search(1, 0);
        f[1] = d[1]; //注意第一步f到d的转移
        mx = 0;
        dfs(1, 0);
        for (int i = 1; i <= n; i++) {
            mx = max(mx, f[i]);
        }
        printf("%d\n", mx);
    }
    return 0;
}
