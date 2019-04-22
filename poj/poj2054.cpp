//经过推理以后可以发现，树中出根节点外最大的
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,r,now,x,y,ans,fa[1200],vis[1200],sz[1200],a[1200];
signed main() {
    while(scanf("%d%d",&n,&r)!=EOF && n && r) {
        memset(vis,0,sizeof vis);
        For(i,1,n) scanf("%d",&a[i]);
        For(i,1,n) sz[i]=1;
        For(i,1,n-1) {
            scanf("%d%d",&x,&y);
            fa[y]=x;
        }
        ans=0;
        For(i,1,n-1) {
            double mx=-0x3f3f3f3f;
            For(j,1,n) if(!vis[j] && j!=r && (double)a[j]/sz[j]>mx) {//整个的平均权值最大的点
                mx=(double)a[j]/sz[j];
                now=j;
            }
            vis[now]=1;
            int up=fa[now];
            while(vis[up]) up=fa[up];//最上面的一个点
            ans+=sz[up]*a[now];
            a[up]+=a[now];
            sz[up]+=sz[now];
            For(j,1,n) if(fa[j]==now) fa[j]=up;//把两个点合并
            fa[now]=up;
        }
        cout<<ans+a[r]<<'\n';
    }   
    return 0;
}