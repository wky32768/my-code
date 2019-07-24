#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define il inline
#define re register 
using namespace std;
il int read() {
    re int f=0,x=0; re char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
il void write(int x) {
    if(x<0) putchar('-'),x=-x;
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}
const int N=500005;
int n,m,cnt,head[N<<1],x,y,z,lca1,lca2,lca3,fa[N][21],depth[N],now,ans;
struct node {int next,to;} sxd[N<<1];
il void add(int u,int v) {sxd[++cnt]=(node) {head[u],v};head[u]=cnt;}
il void dfs(int x,int f) {
    for(re int i=1;(1<<i)<=depth[x];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
    for(re int i=head[x];i;i=sxd[i].next) {
        if(sxd[i].to==f) continue;
        fa[sxd[i].to][0]=x;
        depth[sxd[i].to]=depth[x]+1;
        dfs(sxd[i].to,x);
    }
}
il int lca(int x,int y) {
    if(depth[x]<depth[y]) swap(x,y);
    for(re int i=20;i>=0;i--) if(depth[fa[x][i]]>=depth[y]) x=fa[x][i];
    if(x==y) return x;
    for(re int i=20;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
signed main() {
    n=read(),m=read();
    For(i,1,n-1) {x=read(),y=read(),add(x,y),add(y, x);}
    depth[0]=-1;dfs(1,0); 
    For(i,1,m) {
        x=read(),y=read(),z=read(),lca1=lca(x,y),lca2=lca(x,z),lca3=lca(y,z);
        //分析可得，最大深度的LCA即为答案，然后手酸狮子即可(什么轮换式最好看了)
        now=lca1^lca2^lca3;
        ans=depth[x]+depth[y]+depth[z]-depth[lca1]-depth[lca2]-depth[lca3];
        write(now),putchar(' '),write(ans),puts("");
    }
}