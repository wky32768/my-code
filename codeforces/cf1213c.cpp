#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int t,n,m,ans;
bool vis[12];
signed main() {
    t=read();
    while(t--) {
        n=read(),m=read();
        memset(vis,0,sizeof vis);
        int now=m,tot=0;
        if(n<m) {puts("0"); continue;}
        for(;now<=n;now+=m) {if(vis[now%10]==1) break;tot+=now%10;vis[now%10]=1;}
        now-=m;
        ans=tot*(n/now);
        for(register int i=n/now*now+m;i<=n;i+=m) ans+=i%10;
        write(ans); puts("");
    }
    return 0;
}