#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N = 1200;
int t,n,a[N];
signed main() {
    t=read();
    while (t--) {
        bool ok = true;
        n=read();
        n*=4;
        For(i,1,n) a[i] = read();
        sort(a+1,a+n+1);
        int l=1,r=n,s=0;
        while (l<=r) {
            if(r-l+1<4) ok=false;
            if(a[l]!=a[l+1]) ok=false;
            if(a[r]!=a[r-1]) ok=false;
            if(a[l]*a[r]!=s) {
                if(s==0) s=a[l]*a[r];
                else ok=false;
            }
            l+=2,r-=2;
        }
        puts(ok==true?"YES":"NO");
    }
    return 0;
}