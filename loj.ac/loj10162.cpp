/*
基环树，就是NOIP2018D2T1的那个东西
基本操作是先找环，然后对每一个环上的点向下DFS
其他的更没有上司的舞会差不多
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2300000;
int n, x, y, cnt, rt, ans, dp[N][2], head[N], val[N], vis[N], fa[N];
struct node {
    int next, to;
} sxd[N];
void add(int u, int v) {
    sxd[++cnt].next = head[u];
    sxd[cnt].to = v;
    head[u] = cnt;
}
void dfs(int at) {
    vis[at] = 1;
    dp[at][1] = val[at];
    dp[at][0]=0;
    for (int i = head[at]; i; i = sxd[i].next) {
        if(sxd[i].to!=rt) {
            dfs(sxd[i].to);
            dp[at][0]+=max(dp[sxd[i].to][1],dp[sxd[i].to][0]);
            dp[at][1]+=dp[sxd[i].to][0];
        } else dp[sxd[i].to][1]=-0x3f3f3f3f;
    }
}
void find_circle(int at) {
    /*环上找点*/
    vis[at] = 1;
    rt = at;
    while (!vis[fa[rt]]) {
        rt = fa[rt];
        vis[rt] = 1;
    }
    dfs(rt);
    int now = max(dp[rt][0], dp[rt][1]);
    vis[rt]=1;
    rt = fa[rt];
    dfs(rt);
    ans += max(now, max(dp[rt][0], dp[rt][1]));
    /*
    Q:为什么用任意一对进行操作就可以了？
    A:因为这是基环树与普通树的区别，选A不选B,选B不选A
    */
}
signed main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &val[i], &x);
        fa[i] = x;
        add(x, i);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            find_circle(i);
    cout << ans;
    return 0;
}