#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=160000;
int t,n,a[N],ans,mn;
signed main() {
    t=read();
    while(t--) {
        n=read();
        For(i,1,n) a[i]=read();
        mn=0x3f3f3f3f,ans=0;
        for(register int i=n;i>=1;i--) {
            if(a[i]>mn) ans++;
            mn=min(mn,a[i]);
        }
        write(ans); puts("");
    }
    return 0;
}