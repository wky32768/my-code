#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int ksm(int a,int b,int mod) {
	int ans=1;	
	while(b) {
		if(b&1) ans=(ans*a)%mod;
		b>>=1;		
		a=(a*a)%mod;
	}
	return ans;
}
int t,mod,n,ans;
signed main() {
	cin>>t;
	while(t--) {
		cin>>mod>>n;
		ans=0;
		while(n--) {
			int a,b;
			cin>>a>>b;
			ans=(ans+ksm(a,b,mod))%mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

