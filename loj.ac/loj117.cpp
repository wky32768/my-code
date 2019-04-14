/*
模仿上面的思路。还是先从t向s连一条 infinf
的边，然后从ss向tt跑最大流。上面我们为了让这个图把没有流满的自由流流掉，又从s向t跑了一遍最大流。现在我们要让它把多流的部分“吐出来”，因此我们可以再从t向s跑一遍最大流。注意跑之前一定要把t->s的那条流量为
infinf 的边去掉（上下界最大流里不用去是因为我们利用了这条边来简化计算答案的过程）。

记第一次从ss向tt跑最大流后t->s的那条边的流量为 ff ，第二次从t向s跑出的最大流为 maxflow(t,s)maxflow(t,s)
，则该问题的最终答案为 f+maxflow(t,s)f+maxflow(t,s) 。（注意体会与上下界最大流的异曲同工之处）

为什么这样求出的一定是最小流？

首先，这样求出的一定是可行流。现在我们如果去掉ss和tt，图上留下的部分肯定是不满足流量平衡的，但是它表示的实际意义是满足流量平衡的，因为还要加上“下界”（没有体现在图上）。而我们从t到s跑最大流时，每次增广，都在一条路径上减去相同的流量，因此仍然满足流量平衡。又因为下界不在我们的图上，我们的图上的流量实际上表示的是我们在下界的基础上要增加的量，而图的流量总是不为负的，因此不管怎么增广，图中的流量不可能低于下界。综合上述两点，这样的方法t->s跑完最大流后得到的一定是可行流。

其次，减去t->s求出的最大流后答案一定最小。因为如果可行流还能更小，我们在t->s跑最大流时就一定还能增广。换言之，因为我们使用的是求最大流的算法，我们一定在原图上把能流的部分都增广掉，因此减去这部分后得到的一定是最小流。
*/
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
                         depth[N];  //为了能异或访问相对的流所以cnt=1
struct node {
    int next, to, w;
} sxd[N << 1];
inline void add(int u, int v, int w) {
    sxd[++cnt].next = head[u];
    sxd[cnt].to = v;
    sxd[cnt].w = w;
    head[u] = cnt;
}
inline bool bfs() {
    queue<int> q;
    while (!q.empty()) q.pop();
    memset(depth, 0, sizeof depth);
    q.push(s);
    depth[s] = 1;
    for (int i=1;i<=n+2;++i) wky[i]=head[i];
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (register int i = head[now]; i; i = sxd[i].next) {
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
    for (register int i = wky[at]; i && rest; i = sxd[i].next) {
        wky[at]=i;//当前弧优化，已经走过的边不用再走了，下一次要记得更新
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
    }  //①找到增广路②计算贡献
    return ans;
}
int bout[N], low[N];
signed main() {
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    memset(head, 0, sizeof head);
    memset(bout, 0, sizeof bout);
    cnt = 1;
    for (register int i = 1; i <= m; i++) {
        int a, b, c, d;
        a = read(), b = read(), c = read(), d = read();
        add(a, b, d - c);
        add(b, a, 0);
        bout[a] += c;
        bout[b] -= c;
        low[i] = c;
    }
    int ss = n + 1, tt = n + 2, sum = 0, sss = s, ttt = t;
    for (register int i = 1; i <= n; i++) {
        if (bout[i] > 0) {
            sum += bout[i];
            add(i, tt, bout[i]);
            add(tt, i, 0);
        }
        if (bout[i] < 0) {
            add(ss, i, -bout[i]);
            add(i, ss, 0);
        }
    }
    add(t, s, 0x3f3f3f3f);
    add(s, t, 0);
    s = ss, t = tt;
    if (sum == dinic()) {
        int pfy=sxd[cnt].w;
        head[ttt] = sxd[head[ttt]].next;
        head[sss] = sxd[head[sss]].next;
        s = ttt, t = sss;
        cout << pfy - dinic() << '\n';
    } else
        puts("please go home to sleep");
    return 0;
}