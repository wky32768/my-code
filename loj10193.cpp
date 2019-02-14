#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,a,b,c,d;
const int mod=200907;
int ksm(int a,int b) {
	int ans=1;
	while(b) {
		if(b%2==1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
signed main() {
	cin>>t;
	while(t--) {
		cin>>a>>b>>c>>d;
		if(c-b==b-a) cout<<(a+(d-1)%mod*(b-a)%mod)%mod;
		else cout<<a%mod*ksm((b/a)%mod,(d-1))%mod;
		puts("");
	}
	return 0;
}