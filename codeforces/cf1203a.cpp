#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=1200;
int t,n,a[N];
signed main() {
    t=read();
    while (t--) {
        n=read();
        For(i,1,n) {a[i] = read();a[i]--;}
        int which=0,ok=1;
        if(a[2]==((a[1]+1)%n)) which=1; 
        else which=2; 
        For(i,3,n) {
            if(which==1 && !(a[i]==(a[i-1]+1)%n)) ok=0;
            if(which==2 && !(a[i]==(a[i-1]-1+n)%n)) ok=0;
        }
        puts((ok==1?"YES":"NO"));
    }
    return 0;
}
