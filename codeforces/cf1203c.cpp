#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N = 420000;
int n,a[N],gg;
inline int solve(int x) {
    if(x==1) return 1;
    int tot=0;
    for(register int i=2;i*i<=x;i++) if(x%i==0) {
        if(i*i==x) tot++;
        else tot+=2;
    }
    return tot+2;
}
signed main() {
    n=read();
    For(i,1,n) a[i]=read();
    gg=a[1];
    For(i,2,n) gg=__gcd(gg,a[i]);
    cout<<solve(gg);
    return 0;
}