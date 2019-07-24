#include <bits/stdc++.h>
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
const int N = 100005;
int head[N], cnt, n, m1, m2, x, y, low[N], dfn[N], haha, tot, belong[N], sz[N], dis[605][605], times[N], ans;
bool vis[N];
stack<int> st;
struct node {
    int next, to, w;
} sxd[N << 1];
inline void add(int u, int v, int w) {
    sxd[++cnt].next = head[u];
    sxd[cnt].to = v;
    sxd[cnt].w = w;
    head[u] = cnt;
}
inline void tarjan(int x) {
    dfn[x] = low[x] = ++haha;
    st.push(x);
    vis[x] = 1;
    for (register int i = head[x]; i; i = sxd[i].next) {
        int now = sxd[i].to;
        if (!dfn[now]) {
            tarjan(now);
            low[x] = min(low[x], low[now]);
        } else if (vis[now])
            low[x] = min(low[x], dfn[now]);
    }
    if (low[x] == dfn[x]) {
        tot++;
        while(1) {
            if(st.empty()) break;
            int now=st.top();
            st.pop();
            belong[now]=tot;
            sz[tot]++;
            vis[now]=0;
            if(now==x) break;
        }
    }
}
queue<int> q;
inline bool spfa(int x) {
    memset(dis[x], 0x3f, sizeof dis[x]);
    memset(vis, 0, sizeof vis);
    memset(times, 0, sizeof times);
    while (!q.empty())
        q.pop();
    q.push(x);
    dis[x][x] = 0;
    vis[x]=1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for (register int i = head[now]; i; i = sxd[i].next) {
            int v = sxd[i].to, w = sxd[i].w;
            if (belong[now] != belong[v])
                continue;
            if (dis[x][now] + w < dis[x][v]) {
                dis[x][v] = dis[x][now] + w;
                times[v]++;
                if (times[v] > sz[belong[v]])
                    return 0;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return 1;
}
signed main() {
    cin >> n >> m1 >> m2;
    For(i, 1, m1) {
        cin >> x >> y;
        add(x, y, -1), add(y, x, 1);
    }
    For(i, 1, m2) {
        cin >> x >> y;
        add(x, y, 0);
    }
    For(i, 1, n) if (!dfn[i]) tarjan(i);
    For(i, 1, n) if (!spfa(i)) return puts("NIE"), 0;
    For(i, 1, tot) {
        int mx = 0;
        For(j, 1, n) For(k, 1, n) if (belong[j] == i && belong[k] == i) mx = max(mx, dis[j][k]);
        ans += mx + 1; //求元素不同的最大值等价于连通块内的最长路+1(以为所有的边权都是-1，0或1，所以把整个强连通分量拉紧，最长路就是最大的取值范围-1)
    }
    cout << ans;
}