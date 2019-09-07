#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int mod=998244353;
int ok[1200][1200];
inline int ksm(int x,int y) {
	int ans=1;
	while(y) {
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
inline int f(int x,int y) {
	if(ok[x][y]!=0) return ok[x][y];
	if(x==1) {ok[x][y]=2;return ok[x][y];}
	if(x>=2 && x<=42 && y==0) {ok[x][y]=ksm(2,x)%mod;return ok[x][y];}
	if(x>=43 && y==0) {
		int now=1;
		For(i,1,42) now=(now*ksm(f(x-i,y),i))%mod;	
		ok[x][y]=now;
		return ok[x][y];
	}
	if(y>=1) {
		ok[x][y]=f(x-1,y)*f(x,y-1)%mod;
		return ok[x][y];
	}
	return 0;
}
signed main() {
	int x=read(),y=read();
	cout<<f(x,y);
	return 0;
}

