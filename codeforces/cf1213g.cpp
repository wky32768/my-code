#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=200005;
int n,m,fa[N],sz[N],ans[N];
struct node {int ask,id;} q[N];
struct edge {int a,b,w;} sxd[N];
inline bool cmp(edge a,edge b) {return a.w<b.w;}
inline int find(int x) {if(fa[x]==x) return x; return fa[x]=find(fa[x]);}
int tot[N],tree[N<<2];
inline void build(int rt,int l,int r) {
    if(l==r) {
        tree[rt]=tot[l];
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
inline int zhao(int L,int R,int l,int r,int rt) {
    if(L<=l && r<=R) return tree[rt];
    int mid=(l+r)>>1,zong=0;
    if(L<=mid) zong+=zhao(L,R,l,mid,rt<<1);
    if(R>mid) zong+=zhao(L,R,mid+1,r,rt<<1|1);
    return zong;
}
signed main() {
    n=read(),m=read();
    For(i,1,n-1) sxd[i].a=read(),sxd[i].b=read(),sxd[i].w=read();
    For(i,1,m) q[i].ask=read();
    sort(sxd+1,sxd+n,cmp);
    For(i,1,n) fa[i]=i,sz[i]=1;
    int now=sxd[1].w,at=1;
    at=1;
    if(n==1) {For(i,1,m) cout<<"0 "; return 0;}
    fa[sxd[1].b]=sxd[1].a;
    sz[sxd[1].a]=2; 
    tot[sxd[1].w]=1; 
    For(i,2,n-1) {
        int xx=find(sxd[i].a),yy=find(sxd[i].b);
        if(sz[xx]>sz[yy]) swap(xx,yy);
        now=max(now,sxd[i].w);
        at=1;
        tot[now]+=sz[yy]*sz[xx];
        fa[xx]=yy;
        sz[yy]+=sz[xx];
    }
    build(1,1,n);
    For(i,1,m) {write(zhao(1,q[i].ask,1,n,1));putchar(' ');}
    return 0;
}