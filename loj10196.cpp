#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=100003;
int ksm(int a,int b) {
	int ans=1;
	while(b) {
		if(b%2==1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
int n,m;
signed main() {
	cin>>m>>n;
	cout<<((ksm(m,n)-m*ksm(m-1,n-1))%mod+mod)%mod;
	return 0;
}