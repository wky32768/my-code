//每一条边对起点的贡献=(f[y]+w)/du
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, x, y, z, cnt, head[240000], du[240000], out[240000];
double f[240000];
queue<int> q;
struct node {
    int next, to, w;
} sxd[480000];
void add(int u, int v, int w) {
    sxd[++cnt].next = head[u];
    sxd[cnt].to = v;
    sxd[cnt].w = w;
    head[u] = cnt;
}
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &x, &y, &z);
        add(y, x, z);
        du[x]++, out[x]++;
    }
    q.push(n);
    while (!q.empty()) {
        int at = q.front();
        q.pop();
        for (int i = head[at]; i; i = sxd[i].next) {
            f[sxd[i].to] += (double)((double)(f[at] + (double)sxd[i].w) / (double)du[sxd[i].to]);
            out[sxd[i].to]--;
            if (out[sxd[i].to] == 0)
                q.push(sxd[i].to);
        }
    }
    printf("%.2lf",f[1]);
    return 0;
}