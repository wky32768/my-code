#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int t,a,b,n;
signed main() {
    t=read();
    while(t--) {
        a=read(),b=read(),n=read();
        if(n%3==0) write(a);
        else if(n%3==1) write(b);
        else write(a^b);
        puts("");
    }
    return 0;
}