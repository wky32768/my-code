#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,w[1200],f[1200][1200],sum[1200];
signed main() {
    scanf("%lld",&n);
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&w[i]);
        sum[i]=sum[i-1]+w[i];
        f[i][i]=0;
    }
    for(int len=2;len<=n;len++) {
        for(int l=1;l+len-1<=n;l++) {
            int r=l+len-1;
            for(int i=l;i<r;i++) {
                f[l][r]=min(f[l][r],f[l][i]+f[i+1][r]);
            }
            f[l][r]+=sum[r]-sum[l-1];
        }
    }
    printf("%lld",f[1][n]);
    return 0;
}