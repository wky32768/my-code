//https://www.luogu.org/blog/top-oier/qian-tan-you-shang-xia-jie-di-wang-lao-liu
/*我们在上面问题的基础上思考这个问题。无源汇时，所有点的流入流量都等于流出流量。而本题中只有两个点例外：源点s和汇点t。因此我们想到从t向s拉一条下界为0上界为INF的边，这样有源汇的问题就解决了。

我们接下来要考虑的是：之前可行流的方法跑出来的流量（也就是我们刚刚建的t到s的这条边上的流量）是否一定是最大流？答案是否定的。

根据最大流的算法，当第一遍最大流跑完以后，从ss到tt的路径已经不能再增广了。但是我们从ss向tt跑最大流，只是用超级源、汇表示了原来的下界，求得了满足“下界”的一种方案。但是网络上可能还有一些边，与超级源点和超级汇点都没有连边，因此在上一次跑最大流的时候没有利用到他们。也就是说，残量网络上还有一些“自由流”没有流满。因此我们要从原图的源点s向原图的汇点t再跑一次最大流。

这一次跑的最大流代表我们还能增加的流量。因此理论上有源汇上下界最大流的答案就等于第一次跑最大流后t->s那条边上的流量（一种可行流）+第二次在残量网络上从s向t跑出的最大流。但是实际操作中，“第一次跑最大流后t->s那条边上的流量”就等于他的反向边s->t现在的容量。因此当我们第二次从s向t跑最大流时，自然会利用起这部分“容量”，也就是说如果不去掉这条边，这一部分的值已经算在第二次跑出的最大流里面了，没必要再加上。*/
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
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
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
    int ss = n + 1, tt = n + 2, sum = 0, sss = s, ttt = t;
    for (int i = 1; i <= n; i++) {
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
        s=sss,t=ttt;
        cout << dinic() << '\n';
    } else
        puts("please go home to sleep");
    return 0;
}