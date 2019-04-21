#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 120000;
int n, m, t, cnt, x, y, ans,head[N], forbid[230][230], vis[N], girl[N];
struct node {
    int next, to;
} sxd[N << 1];
void add(int u, int v) {
    sxd[++cnt].next = head[u];
    sxd[cnt].to = v;
    head[u] = cnt;
}
bool find(int x) {
    for(int i=head[x];i;i=sxd[i].next) {
        if(!vis[sxd[i].to]) {
            vis[sxd[i].to]=1;
            if((!girl[sxd[i].to]) || find(girl[sxd[i].to])) {
                girl[sxd[i].to]=x;
                return 1;
            }
        }
    }
    return 0;
}
void mx_match() {
    for(int i=1;i<=n;i++) {
        memset(vis,0,sizeof vis);
        if(find(i)) ans++;
    }
    cout<<ans;
    return;
}
signed main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= t; i++) {
        cin >> x >> y;
        forbid[x][y] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!forbid[i][j])
                add(i, j + n);
    mx_match();
    return 0;
}