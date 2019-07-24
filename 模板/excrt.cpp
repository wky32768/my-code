#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=120000;
int n,a[N],b[N],m[N],t[N],M,ans;
void exgcd(int a,int b,int &x,int &y) {
    if(!b) {
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=(a/b)*x;
} 
int gsc(int a,int b,int mod) {
    int ans=0;
    while(b) {
        if(b&1) ans=(ans+a)%mod;
        b>>=1;
        a=(a+a)%mod;
    }
    return ans;
}
void excrt() {
    M=a[1],ans=b[1];
    int x,y,gg;
    For(i,2,n) {
        //x+t*M三b[i](mod a[i])
        //M*t-a[i]*y三b[i]-x(mod a[i])
        int R=(b[i]-ans%a[i]+a[i])%a[i];
        exgcd(M,a[i],x,y);
        gg=__gcd(M,a[i]);
        x=gsc(x,R/gg,a[i]);
        //将原来的GCD解转化成满足题意的解
        ans+=M*x;
        M=M/gg*a[i];//取LCM不影响答案
        ans=(ans+M)%M;
    }
    cout<<ans<<'\n';
}
signed main() {
    cin>>n;
    For(i,1,n) cin>>a[i]>>b[i];
    excrt();
}