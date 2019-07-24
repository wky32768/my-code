#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int mod=1e9+7;
int ans,a,b,k,t,mx,f[101][200005],sum[200005],other[200005];
signed main() {
    cin>>a>>b>>k>>t;
    f[0][100001]=1;
    for(int i=1;i<=200001;i++) sum[i]=sum[i-1]+f[0][i];
    For(i,1,t) {
        For(j,1,200001) {
            int l=max(1ll,j-k),r=min(200001ll,j+k);
            f[i][j]=(sum[r]-sum[l-1]+mod)%mod;//所有上一步结束后可能的取值
            other[j]=(other[j-1]+f[i][j]+mod)%mod;
        }
        For(j,1,200001) sum[j]=other[j];
    }
    For(i,1,200001) {
        int j=i+a-b-1;//另一方至多的毒粉
        if(j<=0) continue;
        j=min(200001ll,j);
        ans=(ans+sum[j]*f[t][i]%mod+mod)%mod;//第一方*第二方
    }
    cout<<ans;
}