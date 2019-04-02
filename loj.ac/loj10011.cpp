#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m,a[120000],ans,l,r;
bool ok(int x) {
	int at=1,tot=1;
	For(i,1,n) if(a[i]-at>=x) {
		tot++;
		at=a[i];
	}
	return tot>=m;
}
signed main() {
	cin>>n>>m;
	For(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	l=1,r=a[n]-a[1];
	while(l<=r) {
		int mid=(l+r)>>1;
		if(ok(mid)) {
			ans=mid;
			l=mid+1;
		} else r=mid-1;
	}
	cout<<ans;
	return 0;
}
