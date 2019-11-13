#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define Dep(i,a,b) for(register int i=a;i>=b;i--)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}

const int N=1000005,mod=1e9+7;
int n,a[N],ans,mi[N];

signed main() {
	n=read();
	For(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	mi[0]=1;
	For(i,1,n) mi[i]=mi[i-1]*2%mod;
	For(i,1,n) {
		ans=(ans+a[i]*mi[i-1]%mod)%mod;
	}
	Dep(i,n,1) {
		ans=(ans-a[i]*mi[n-i]%mod+mod)%mod;
	}
	return cout<<ans,0;
}

