#include <bits/stdc++.h>
#define int long long 
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int mod=1e9+7;
const int N=420;
int a[N][N],b[N][N];
int n;
int ksm(int a,int b) {
    int ans=1;
    while(b) {
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
signed main() {
    cin>>n;
    For(i,1,n) For(j,1,n) cin>>a[i][j];
    For(i,1,n) b[i][i]=1;
    For(i,1,n) {
        int now=a[i][i];
        if(now==0) return puts("No Solution"),0;
        int ni=ksm(a[i][i],mod-2);
        For(j,1,n) a[i][j]=(a[i][j]*ni)%mod;
        For(j,1,n) b[i][j]=(b[i][j]*ni)%mod;
        For(j,1,n) if(j!=i) {
            int sxd=a[j][i];
            For(k,1,n) a[j][k]=(a[j][k]-sxd*a[i][k]%mod+mod)%mod;
            For(k,1,n) b[j][k]=(b[j][k]-sxd*b[i][k]%mod+mod)%mod;
        }
    }
    For(i,1,n) {
        For(j,1,n) cout<<b[i][j]<<" ";
        puts("");
    }
    return 0;
}