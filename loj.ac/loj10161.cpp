/*转移的时候考虑当前放什么，在DP的时候如果子节点的颜色和当前点的颜色一样，当前点子节点是不用放的，所以在统计的时候–就好了*/
#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=120000;
int m,n,x,y,head[N],cnt,c[N],f[N][2];
struct node {int next,to;} sxd[N<<1];
void add(int u,int v) {
    sxd[++cnt].next=head[u];
    sxd[cnt].to=v;
    head[u]=cnt;
}
void dfs(int at,int fa) {
    if(at<=n) {//叶节点
        f[at][c[at]]=1;
        f[at][c[at]^1]=0x3f3f3f3f;
        return;
    }
    f[at][0]=f[at][1]=1;//你的着色方案应该保证根结点到每个叶子的简单路径上都至少包含一个有色结点（哪怕是这个叶子本身）。
    for(int i=head[at];i;i=sxd[i].next) {
        if(sxd[i].to==fa) continue;
        dfs(sxd[i].to,at);
        f[at][0]+=min(f[sxd[i].to][1],f[sxd[i].to][0]-1);
        f[at][1]+=min(f[sxd[i].to][0],f[sxd[i].to][1]-1);
    }
}
signed main() {
    scanf("%lld%lld",&m,&n);
    For(i,1,n) scanf("%lld",&c[i]);
    For(i,1,m-1) {
        scanf("%lld%lld",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(m,0);
    cout<<min(f[m][0],f[m][1]);
    return 0;
}