#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int t,b,p,f,h,c,ans;
signed main() {
    t=read();
    while (t--) {
        b=read(),p = read(),f = read();
        h=read(),c = read();
        ans=0;
        if(h<c) {
            ans=c*min(b/2,f);
            b-=2*min(b/2,f);
            ans+=h*min(b/2,p);
        } else {
            ans=h*min(b/2,p);
            b-=2*min(b/2,p);
            ans+=c*min(b/2,f);
        }
        cout<<ans<<'\n';
    }
    return 0;
}