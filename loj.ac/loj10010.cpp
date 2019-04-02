#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,a[1200000],s[1200000],ans,tot,candy,b;
signed main() {
	cin>>n;
	For(i,1,n) {
		cin>>a[i];
		tot+=a[i];
	}
	b=tot/n;
	For(i,1,n) {
		a[i]-=b;
		s[i]=s[i-1]+a[i];
	}
	sort(s+1,s+n+1);
	candy=s[(n+1)/2];
	For(i,1,n) ans+=abs(candy-s[i]);
	cout<<ans;
	return 0;
}