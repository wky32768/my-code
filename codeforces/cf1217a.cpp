#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int t,a,b,c,ans;
signed main() {
	t=read();
	while(t--) {
		a=read(),b=read(),c=read();
		int l=0,r=c,ans=0;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(a+mid>b+(c-mid)) {
				ans=mid;
				r=mid-1;
			} else l=mid+1;
		}
		if(a+c<=b) puts("0");
		else cout<<c-ans+1<<'\n';
	}
	return 0;
}

