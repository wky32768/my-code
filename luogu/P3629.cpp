//每条原先在直径里面的值，如果被第二条边连上，就一定会夺走一遍，所以权值是-1
#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
const int N=100005;
int head[N<<1],cnt=1,n,k,ans,x,y,at1[N],at2[N],mx,mx_gen;//存储使用了那一条边（方便修改点权）
struct node {int next,to,w;} sxd[N<<1];
inline void add(int u,int v) {sxd[++cnt]=(node) {head[u],v,1};head[u]=cnt;}
int dfs(int x,int f) {
    int mx1=0,mx2=0;
    for(int i=head[x];i;i=sxd[i].next) {
        if(sxd[i].to==f) continue;
        int now_ans=dfs(sxd[i].to,x)+sxd[i].w;
        if(now_ans>mx1) mx2=mx1,at2[x]=at1[x],mx1=now_ans,at1[x]=i;
        else if(now_ans>mx2) mx2=now_ans,at2[x]=i;
    }
    if(mx1+mx2>mx) mx=mx1+mx2,mx_gen=x;
    return mx1;
}
signed main() {
    n=read(),k=read();
    For(i,1,n-1) {x=read(),y=read(),add(x,y),add(y,x);}
    ans=(n-1)*2;//每条边都走两遍
    dfs(1,0);
    ans-=(mx-1);
    if(k==2) {
        for(int i=at1[mx_gen];i;i=at1[sxd[i].to]) sxd[i].w=sxd[i^1].w=-1;
        for(int i=at2[mx_gen];i;i=at1[sxd[i].to]) sxd[i].w=sxd[i^1].w=-1;//这里写错了，第二长边向下推仍然是最长的（80分了）
        mx=0;
        dfs(1,0);
        ans-=(mx-1);
    }
    cout<<ans;
    return 0;
}