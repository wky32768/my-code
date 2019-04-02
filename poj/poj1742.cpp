/*多重背包的优化，记录当前用了几个*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[120000],c[120000],used[120000],ans;
bool f[120000];
signed main() {
    while(scanf("%lld%lld",&n,&m) && n && m) {
        memset(f,0,sizeof f);
        memset(used,0,sizeof used);
        ans=0;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
        f[0]=1;
        for(int i=1;i<=n;i++) {
            memset(used,0,sizeof used);
            for(int j=a[i];j<=m;j++)
                if(f[j]==0 && f[j-a[i]]!=0 && used[j-a[i]]<c[i]) {
                    f[j]=1;
                    used[j]=used[j-a[i]]+1;
                }
        }
        for(int i=1;i<=m;i++) if(f[i]) ans++;
        printf("%lld\n",ans);
    }
    return 0;
}