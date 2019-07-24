#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=120;
int n,a[N],b[N],m[N],t[N];
void exgcd(int a,int b,int &x,int &y) {
    if(!b) {
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=(a/b)*x;
} 
void crt() {
    int M=1,x,y,ans=0;
    For(i,1,n) M*=a[i];
    For(i,1,n) m[i]=M/a[i];
    //m[i]*T[i]三1(mod a[i])
    //m[i]*x(T[i])+a[i]*y=1
    For(i,1,n) {
        exgcd(m[i],a[i],x,y);
        t[i]=x;
    }
    For(i,1,n) ans=(ans+b[i]*m[i]*t[i])%M;
    ans=(ans+M)%M;
    cout<<ans;
}
signed main() {
    cin>>n;
    For(i,1,n) cin>>a[i]>>b[i];
    crt();
}