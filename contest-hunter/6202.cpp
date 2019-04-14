#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const long long mod = (1ll << 31) - 1;
int n,m,x,y,z,ans,dis[120000],a[1200][1200];
bool vis[120000];
signed main() {
    scanf("%lld%lld",&n,&m);
    memset(a,0x3f,sizeof a);
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    For(i,1,n) a[i][i]=0;
    For(i,1,m) {
        scanf("%lld%lld%lld",&x,&y,&z);
        a[x][y]=a[y][x]=min(a[x][y],z);
    }
    For(i,1,n-1) {
        int at=0;
        For(j,1,n) if(!vis[j] && (at==0 || dis[at]>dis[j])) at=j;
        vis[at]=1;
        For(j,1,n) dis[j]=min(dis[j],dis[at]+a[at][j]);
    }
    memset(vis,0,sizeof vis);
    vis[1]=1;
    ans=1;
    For(i,1,n-1) {
        int at=0,now=0;
        For(j,2,n) if(!vis[j] && (at==0 || dis[at]>dis[j])) at=j;
        For(j,1,n) if(vis[j] && dis[j]+a[j][at]==dis[at]) now++;
        vis[at]=1;
        ans=(ans*now)%mod;
    }
    cout<<ans;
    return 0;
}
