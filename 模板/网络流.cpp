// https://blog.csdn.net/txl199106/article/details/64441994
#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
const int N = 230000;
inline int read() {
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
int n, m, s, t, x, y, z, cnt = 1, head[N << 1],wky[N<<1],
                         depth[N]; //为了能异或访问相对的流所以cnt=1
struct node {
    int next, to, w;
} sxd[N << 1];
void add(int u, int v, int w) {
    sxd[++cnt].next = head[u];
    sxd[cnt].to = v;
    sxd[cnt].w = w;
    head[u] = cnt;
}
bool bfs() {
    queue<int> q;
    while (!q.empty())
        q.pop();
    memset(depth, 0, sizeof depth);
    for(int i=1;i<=n+2;i++) wky[i]=head[i];
    q.push(s);
    depth[s] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = head[now]; i; i = sxd[i].next) {
            if (sxd[i].w > 0 && depth[sxd[i].to] == 0) {
                depth[sxd[i].to] = depth[now] + 1;
                q.push(sxd[i].to);
                if (sxd[i].to == t)
                    return 1;
            }
        }
    }
    return 0;
}
inline int dfs(int at, int val) {
    if (at == t)
        return val;
    int rest = val;
    for (int i = wky[at]; i && rest; i = sxd[i].next) {
        wky[at]=i;
        if (depth[sxd[i].to] == depth[at] + 1 && sxd[i].w) {
            int carrot = dfs(sxd[i].to, min(rest, sxd[i].w));
            if (!carrot)
                depth[sxd[i].to] = 0;
            sxd[i].w -= carrot;
            sxd[i ^ 1].w += carrot;
            rest -= carrot;
        }
    }
    return val - rest;
}
inline int dinic() {
    int ans = 0;
    while (bfs()) {
        ans += dfs(s, 0x3f3f3f3f);
    } //①找到增广路②计算贡献
    return ans;
}
signed main() {
    n = read(), m = read(), s = read(), t = read();
    For(i, 1, m) {
        x = read(), y = read(), z = read();
        add(x, y, z);
        add(y, x, 0);
    }
    cout << dinic();
    return 0;
}