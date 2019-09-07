#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int n,l,r;
signed main() {
    n=read(),l=read(),r=read();
    int mn=1,mx=1,now1=1,now2=1;
    For(i,2,n+1-l) {
        mn+=1;
    }
    For(i,n+1-l+1,n) {
        now1*=2;
        mn+=now1;
    }
    For(i,2,min(n,r)) {
        now2*=2;
        mx+=now2;
    }
    For(i,min(n,r)+1,n) {
        mx+=now2;
    }
    cout<<mn<<" "<<mx<<'\n';
    return 0;
}