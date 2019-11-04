#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=1005;
int n,a[N][N];
signed main() {
	n=read();
	For(i,1,n) For(j,1,n) a[i][j]=read();
	For(i,1,n) {write(sqrt(a[i][i+1==n+1?1:i+1]*a[i][i-1==0?n:i-1]/a[i+1==n+1?1:i+1][i-1==0?n:i-1]));putchar(' ');}
	return 0;
}

