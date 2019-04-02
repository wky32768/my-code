#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=10007;
int a,b,x,y,c,d,k,n,m,ni,ans;
int fac[12000];
void exgcd(int a,int b,int &x,int &y) {
    if(!b) {
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=(a/b)*x;
}
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
    cin>>a>>b>>k>>n>>m;
    fac[0]=1;
    n=min(n,m);
    for(int i=1;i<=1000;i++) fac[i]=fac[i-1]*i%mod;
    ans=1;
    ans=(ans*ksm(a,n))%mod;
    ans=(ans*ksm(b,m))%mod;
    ans=(ans*fac[k])%mod;
    exgcd(fac[n],mod,ni,y);
    ans=(ans*ni)%mod;
    exgcd(fac[k-n],mod,ni,y);
    ans=(ans*ni)%mod;
    cout<<(ans+mod)%mod;
    return 0;
}