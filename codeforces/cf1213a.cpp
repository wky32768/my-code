#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N =120;
int n,ji,ou,a[N];
signed main() {
	n=read();
    For(i,1,n) {
        a[i]=read();
        if(a[i]%2==1) ji++;
        else ou++;
    }
    cout<<min(ji,ou);
    return 0;
}

