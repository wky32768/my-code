#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1200000;
int cnt,head[N],n,m,x,y,rt,a[N],ans[N];
bool vis[N];
struct node {int next,to;} sxd[N<<1];
void add(int u,int v) {
    sxd[++cnt]=(node) {head[u],v};
    head[u]=cnt;
}
void dfs(int x,int f) {
    vis[x]=1;
    ans[++ans[0]]=x;
    a[x]^=1;
    for(int i=head[x];i;i=sxd[i].next) 
        if(sxd[i].to!=f && vis[sxd[i].to]==0) {
            dfs(sxd[i].to,x);
            ans[++ans[0]]=x;
            a[x]^=1;//回溯
        }
    if(a[x]) {
        ans[++ans[0]]=f,a[f]^=1;
        ans[++ans[0]]=x,a[x]^=1;//奇偶性不对，需要与父亲震荡
    }
}
signed main() { 
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>x>>y;
        add(x,y),add(y,x);
    }
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]) rt=i;
    }
    if(rt==0) {puts("0");return 0;}
    dfs(rt,0);
    for(int i=1;i<=n;i++) if(!vis[i] && a[i]) return puts("-1"),0;//别的联通块出现奇点，爆蛋
    if(ans[ans[0]-1]==0) ans[0]-=3;//最后从根向上回溯，说明ans返回时与需要的不符，所以不返回
    cout<<ans[0]<<'\n';
    for(int i=1;i<=ans[0];i++) cout<<ans[i]<<" ";
    return 0;
}