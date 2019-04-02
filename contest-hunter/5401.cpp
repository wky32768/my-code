#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,x,y,head[120000],f[120000][5],w[120000];
struct node {
    int next,to;
} sxd[120000];
void add(int u,int v) {
    sxd[++cnt].next=head[u];
    sxd[cnt].to=v;
    head[u]=cnt;
}
void dfs(int at,int fa) {
    f[at][0]=0,f[at][1]=w[at];
    for(int i=head[at];i;i=sxd[i].next) {
        if(sxd[i].to==fa) continue;
        dfs(sxd[i].to,at);
        f[at][0]+=max(f[sxd[i].to][0],f[sxd[i].to][1]);
        f[at][1]+=f[sxd[i].to][0];
    }
}
signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n-1;i++) {
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    cin>>x>>y;
    dfs(1,0);
    cout<<max(f[1][0],f[1][1])<<'\n';
    return 0;
}