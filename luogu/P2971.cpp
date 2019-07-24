#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int read() {
    int f=0,x=0;
    char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
const int N=200005;
int n,k,head[N<<1],cnt,x,y,at[N],rt,fa[N][23],w[N],depth[N],mx[N],mxat[N],ans[N];
struct node {
    int next,to;
} sxd[N<<1];
void add(int u,int v) {
    sxd[++cnt]=(node) {head[u],v};
    head[u]=cnt;
}
void dfs(int x,int f) {
    for(int i=head[x];i;i=sxd[i].next) {
        if(sxd[i].to==f) continue;
        depth[sxd[i].to]=depth[x]+1;
        fa[sxd[i].to][0]=x;
        dfs(sxd[i].to,x);
    }
}
void bz() {
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
}
int lca(int x,int y) {
    if(depth[x]<depth[y]) swap(x,y);
    for(int i=20;i>=0;i--) if(depth[fa[x][i]]>=depth[y]) x=fa[x][i];
    if(x==y) return x;
    for(int i=20;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
signed main() {
    n=read(),k=read();
    For(i,1,n) {
        w[i]=read(),fa[i][0]=read();
        if(fa[i][0]==0) rt=i;
        add(i,fa[i][0]);
        add(fa[i][0],i);
    }
    dfs(rt,0);
    bz();
    For(i,1,n) {
        if(mx[w[i]]<depth[i]) {
            mx[w[i]]=depth[i];
            mxat[w[i]]=i;
        }
    }
    For(i,1,n) {
        int now=lca(mxat[w[i]],i);
        ans[w[i]]=max(ans[w[i]],mx[w[i]]-depth[now]+depth[i]-depth[now]);
    }
    For(i,1,k) cout<<ans[i]<<'\n';
    return 0;
}