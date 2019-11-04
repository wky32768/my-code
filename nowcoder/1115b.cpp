#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}

const int mod=1e9+7;
const int N=1000005;
int n,k,fac[N];

inline int ksm(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;	
	}
	return ans;
}

inline int C(int n,int m) {
	return fac[n]*ksm(fac[m],mod-2)%mod*ksm(fac[n-m],mod-2)%mod;	
}

signed main() {
	n=read(),k=read();
	fac[0]=1;
	For(i,1,n) fac[i]=fac[i-1]*i%mod;
	if(k==0) return puts("1"),0;
	if(k%2==1) {
		cout<<C((n-1)-(k-1)/2,(k-1)/2);
	} else {
		cout<<C((n-2)-(k-2)/2,(k-2)/2);
	}
	return 0;
}

