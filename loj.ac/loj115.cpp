//https://blog.csdn.net/winter2121/article/details/79430071
// 方法：将下界分离出来。
// 1）对于每条边(u,v)：cap = c-b    //自由容量，将下界分离
// 2）设数组bout[]，记录每一个点的 出边下界和 减 入边下界和。
// 设虚拟源点SS，虚拟汇点TT
// 遍历点，对每一个点u：
// 若bout[u]>0   建立边 (u,TT) cap=bout[u]。
// 若bout[u]<0   建立边(SS,u) cap= - bout [u]，
// 设变量bflow记录所有(u,TT) cap之和（用于验证满流）
// 4）求SS -> TT的最大流，若等于bflow，则存在可行流，否则图不流通。
//  #理解#：
// c-b是多余的容量，可流可不流，称为自由流，建立这样的边，就可用普通的网络流求最大流了。
// 对于分离出来的下界边，则要要求他们全部满流！
// 出边连接tt，入边连接ss，求ss->tt的最大流，若等于下界出边之和（或入边之和）则说明下界全部满流了。
// 可行流的计算：若验证存在可行流，每一条边的真实流量=下界+新图中该边流量
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
int n, m, s, t, x, y, z, cnt = 1, head[N << 1],
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
    q.push(s);
    depth[s] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = head[now]; i; i = sxd[i].next) {
            if (sxd[i].w > 0 && depth[sxd[i].to] == 0) {
                depth[sxd[i].to] = depth[now] + 1;
                q.push(sxd[i].to);
                if(sxd[i].to==t) return 1;
            }
        }
    }
    return 0;
}
inline int dfs(int at, int val) {
    if (at == t)
        return val;
    int rest = val;
    for (int i = head[at]; i && rest; i = sxd[i].next) {
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
int bout[N], low[N];
signed main() {
    scanf("%lld%lld", &n, &m);
    memset(head, 0, sizeof head);
    memset(bout, 0, sizeof bout);
    cnt = 1;
    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        add(a, b, d - c);
        add(b, a, 0);
        bout[a] += c;
        bout[b] -= c;
        low[i] = c;
    }
    int ss = n + 1, tt = n + 2, sum = 0;
    for (int i = 1; i <= n; i++) {
        if (bout[i] > 0) {
            sum += bout[i];
            add(i, tt, bout[i]);
            add(tt,i,0);
        }
        if (bout[i] < 0) {
            add(ss, i, -bout[i]);
            add(i,ss,0);
        }
    }
    s = ss, t = tt;
    if (sum == dinic()) {
        puts("YES");
        for (int i = 1; i <= m; i++)
            cout << low[i] + sxd[(i << 1)^1].w << '\n';
    } else
        puts("NO");
    return 0;
}