#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int mod=9901;
int a,b,ans=1;
int ksm(int a,int b) {
	int ans=1;
	a%=mod;
	while(b) {
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
int sum(int p,int c) {
	if(c==0) return 1;
	if(c&1) return sum(p,c>>1)*(1+ksm(p,(c+1)/2))%mod;
	return sum(p,c/2-1)*(1+ksm(p,c/2))%mod+ksm(p,c)%mod;
}
signed main() {
	cin>>a>>b;
	for(int i=2; i*i<=a; i++) {
		if(a%i==0) {
			int num=0;
			while(a%i==0) num++,a/=i;
			ans=(ans*sum(i,b*num))%mod;
		}
	}
	if(a!=1) ans=(ans*sum(a,b))%mod;
	cout<<ans;
}
