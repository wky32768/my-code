#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,a[120000];
signed main() {
	cin>>n;
	For(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	if(n%2==0) {
		int ans=0;
		For(i,1,n) ans+=abs(a[n/2]-a[i]);
		cout<<ans;
	} else {
		int ans=0;
		For(i,1,n) ans+=abs(a[n/2+1]-a[i]);
		cout<<ans;
	}
	return 0;
}

