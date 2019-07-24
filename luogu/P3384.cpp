#include <bits/stdc++.h>
#define int long long
#define il inline
#define re register 
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=100005;
il int read() {
    int x=0,f=0;
    char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
il void write(int x) {
    if(x<0) putchar('-'),x=-x;
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}
int n,m,r,mod,a[N],x,y,z,opt;//输入用
int head[N<<1],cnt,depth[N],sz[N],heavy[N],fa[N],tp[N];//树剖用
int b[N],mp[N],tree[N<<2],add[N<<2],tot;//线段树用
struct node {int next,to;} sxd[N<<1];
void add_edge(int u,int v) {sxd[++cnt]=(node) {head[u],v},head[u]=cnt;}
il void dfs1(int x,int f) {
    depth[x]=depth[f]+1;
    sz[x]=1;
    int mx=0,mxat=0;
    for(int i=head[x];i;i=sxd[i].next) {
        int to=sxd[i].to; if(to==f) continue;
        fa[to]=x;
        dfs1(to,x);
        sz[x]+=sz[to];
        if(sz[to]>mx) mx=sz[to],heavy[x]=to;
    }
}
il void dfs2(int x,int top) {
    b[x]=++tot;
    mp[tot]=a[x];
    tp[x]=top;
    if(heavy[x]) dfs2(heavy[x],top);
    for(int i=head[x];i;i=sxd[i].next) {
        if(sxd[i].to==fa[x] || sxd[i].to==heavy[x]) continue;
        dfs2(sxd[i].to,sxd[i].to);
    }
}
il void build(int rt,int l,int r) {
    if(l==r) {tree[rt]=mp[l];return;}
    re int mid=(l+r)>>1;
    build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
    tree[rt]=(tree[rt<<1]+tree[rt<<1|1])%mod;
    return;
}
il void pushdown(int rt,int l,int r) {
    add[rt<<1]=(add[rt<<1]+add[rt])%mod;
	add[rt<<1|1]=(add[rt<<1|1]+add[rt])%mod;
    tree[rt<<1]=(tree[rt<<1]+add[rt]*l)%mod;
	tree[rt<<1|1]=(tree[rt<<1|1]+add[rt]*r)%mod;
    add[rt]=0;
    return;
}
il void jia(int L,int R,int C,int l,int r,int rt) {
    if(L<=l && r<=R) {add[rt]=(add[rt]+C)%mod,tree[rt]=(tree[rt]+C*(r-l+1))%mod;return;}
    re int mid=(l+r)>>1;
    pushdown(rt,mid-l+1,r-mid);
    if(L<=mid) jia(L,R,C,l,mid,rt<<1);
    if(R>mid) jia(L,R,C,mid+1,r,rt<<1|1);
    tree[rt]=(tree[rt<<1]+tree[rt<<1|1])%mod;
    return;
}
il int ask(int L,int R,int l,int r,int rt) {
    if(L<=l && r<=R) return tree[rt]%mod;
    re int mid=(l+r)>>1,ans=0;
    if(add[rt]) pushdown(rt,mid-l+1,r-mid);
    if(L<=mid) ans=(ans+ask(L,R,l,mid,rt<<1))%mod;
    if(R>mid) ans=(ans+ask(L,R,mid+1,r,rt<<1|1))%mod;
    return ans;
}
il void subtask1(int x,int y,int C) {//x到y的路径+C
    C%=mod;
    while(tp[x]!=tp[y]) {
        if(depth[tp[x]]<depth[tp[y]]) swap(x,y);
        jia(b[tp[x]],b[x],C,1,n,1);
        x=fa[tp[x]];
    }
    if(depth[x]>depth[y]) swap(x,y);
    jia(b[x],b[y],C,1,n,1);
} 
il int subtask2(int x,int y) {//求x到y上的路径和
    int now=0;
    while(tp[x]!=tp[y]) {
        if(depth[tp[x]]<depth[tp[y]]) swap(x,y);
        now=(now+ask(b[tp[x]],b[x],1,n,1))%mod;
        x=fa[tp[x]];
    }
    if(depth[x]>depth[y]) swap(x,y);
    now=(now+ask(b[x],b[y],1,n,1))%mod;
    return now;
}
il void subtask3(int x,int C) {jia(b[x],b[x]+sz[x]-1,C,1,n,1);}
il int subtask4(int x) {return ask(b[x],b[x]+sz[x]-1,1,n,1);}
signed main() {
    n=read(),m=read(),r=read(),mod=read();
    For(i,1,n) a[i]=read();
    For(i,1,n-1) x=read(),y=read(),add_edge(x,y),add_edge(y,x);
    dfs1(r,0),dfs2(r,r);
    build(1,1,n);
    while(m--) {
        opt=read();
        if(opt==1) {
            x=read(),y=read(),z=read();
            subtask1(x,y,z);
        } else if(opt==2) {
            x=read(),y=read();
            write(subtask2(x,y));
            puts("");
        } else if(opt==3){
            x=read(),z=read();
            subtask3(x,z);
        } else if(opt==4) {
            x=read();
            write(subtask4(x));
            puts("");
        }
    }
    return 0;
}
