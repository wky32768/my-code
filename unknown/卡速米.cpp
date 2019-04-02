#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int a,b,m;
int ksm(int a,int b,int m) {
	int ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return ans;
}
signed main() {
	cin>>a>>b>>m;
	cout<<ksm(a,b,m);
	return 0;
}

