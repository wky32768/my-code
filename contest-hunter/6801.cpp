#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, t, cnt, x, y, head[120000], girl[120000];
bool vis[120000], used[120000];
struct node {
    int next, to;
} sxd[240000];
void add(int u, int v) {
    sxd[++cnt].next = head[u];
    sxd[cnt].to = v;
    head[u] = cnt;
}
int make(int x, int y) { return (x - 1) * n + y; }
bool find(int x) {
    for (int i = head[x]; i; i = sxd[i].next) {
        if (used[sxd[i].to])
            continue;
        used[sxd[i].to] = 1;
        if ((!girl[sxd[i].to]) || find(girl[sxd[i].to])) {
            girl[sxd[i].to] = x;
            return 1;
        }
    }
    return 0;
}
int mx_match() {
    int ans = 0;
    for (int i = 1; i <= n * n; i++) {
        memset(used, 0, sizeof used);
        ans += find(i);
    }
    return ans;
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
signed main() {
    scanf("%lld%lld", &n, &t);
    while (t--) {
        scanf("%lld%lld", &x, &y);
        vis[make(x, y)] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int wh = 0; wh <= 3; wh++) {
                int xx=i+dx[wh],yy=j+dy[wh];
                if(xx<1 || xx>n || yy<1 || yy>n) continue;
                if (vis[make(i, j)] || vis[make(xx, yy)] ||
                    ((i + j) % 2 == (xx + yy % 2)))
                    continue;
                add(make(i, j), make(xx, yy));
            }
    cout << mx_match()/2;
    return 0;
}
