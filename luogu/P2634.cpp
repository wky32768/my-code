#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {
    int x=0,f=0;
    char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
const int N=120000;
int n,m,head[N],f[N<<1][4],x,y,w,cnt,ans;//f[i][j]:在x的子树里%3=j的数的个数
struct node {int next,to,w;} sxd[N<<1];
inline void add(int u,int v,int w) {sxd[++cnt]=(node) {head[u],v,w};head[u]=cnt;}
void dfs(int x,int fa) {
    f[x][0]=1;//我数我自己
    for(int i=head[x];i;i=sxd[i].next) {
        if(sxd[i].to==fa) continue; 
        dfs(sxd[i].to,x);
        For(j,0,2) ans+=f[sxd[i].to][j]*f[x][((-sxd[i].w%3-j)%3+3)%3];//一个在已经遍历的子树，一个正在访问，可以美剧出所有的情况
        For(j,0,2) f[x][(j+sxd[i].w)%3]+=f[sxd[i].to][j];
    }
}
signed main() {
    n=read();
    For(i,1,n-1) {
        x=read(),y=read(),w=read();
        add(x,y,w),add(y,x,w);
    }
    dfs(1,0);
    ans=ans*2+n;//相互调换，再加上自己选两次
    int gg=__gcd(ans,n*n);
    cout<<ans/gg<<"/"<<n*n/gg;
    return 0;
}