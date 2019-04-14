//用spfa保证最小的花费，在dinic模板上加以修改
//fa上个点，hao上条边（为了找到增广路后倒推，rest_liu剩余流量
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 120000;
int n, m, cnt = 1, ans, head[N], dis[N], fa[N], hao[N], rest_liu[N], a, b, c, d, flow, cost;
bool vis[N];
queue<int> q;
struct node {
    int next, to, dis, liu;
} sxd[N << 1];
void add(int a, int b, int c, int d) {
    sxd[++cnt].next = head[a];
    sxd[cnt].to = b;
    sxd[cnt].liu = c;
    sxd[cnt].dis = d;
    head[a] = cnt;
}
bool make() {
    memset(vis, 0, sizeof vis);
    memset(dis, 0x7f, sizeof dis);
    memset(rest_liu, 0x7f, sizeof rest_liu);
    while (!q.empty())
        q.pop();
    q.push(1);
    dis[1] = 0;
    fa[n] = 0;
    while (!q.empty()) {
        int at = q.front();
        q.pop();
        vis[at] = 0;
        for (int i = head[at]; i; i = sxd[i].next)
            if (sxd[i].liu && dis[at] + sxd[i].dis < dis[sxd[i].to]) {
                dis[sxd[i].to] = dis[at] + sxd[i].dis;
                fa[sxd[i].to] = at;
                hao[sxd[i].to] = i;
                rest_liu[sxd[i].to] = min(rest_liu[at], sxd[i].liu);
                if (!vis[sxd[i].to]) {
                    vis[sxd[i].to] = 1;
                    q.push(sxd[i].to);
                }
            }
    }
    return fa[n];
}
void mx_liu() {
    while (make()) {
        flow += rest_liu[n];
        cost += rest_liu[n] * dis[n];
        for (int i = n; i != 1; i = fa[i]) {
            sxd[hao[i]].liu -= rest_liu[n];
            sxd[hao[i]^1].liu += rest_liu[n];
        }
    }
    cout << flow << " " << cost << '\n';
}
signed main() {
    scanf("%lld%lld", &n, &m);
    while (m--) {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        add(a, b, c, d);
        add(b, a, 0, -d);//这个地方与最大流不同，我非常遗憾没有把他们合并成一样的语句，只能包邮自己记住这里的操作吧，返回路程取相反数，流为0
    }
    mx_liu();
    return 0;
}