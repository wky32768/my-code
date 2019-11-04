#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int t,n,m,ans1,ans2,x,y,mn;
signed main() {
	t=read();
	while(t--) {
		n=read(),m=read();
		int flag=0,mx=-0x3f3f3f3f,mxl=-0x3f3f3f3f;
		For(i,1,n) {
			x=read(),y=read();
			if(x>y) flag=1;
			mx=max(mx,x-y);
			mxl=max(mxl,x);
		}
		if(!flag && m>mxl) puts("-1");
		else {
			if(m<=mxl) write(1);
			else write(1+((m-mxl)%mx==0?(m-mxl)/mx:(m-mxl)/mx+1)); 
			puts("");
		}
	}
	return 0;
}

