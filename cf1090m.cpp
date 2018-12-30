#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int a[120000],n,k,ans=1,now;
signed main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	now=1;
	for(int i=2;i<=n;i++) {
		if(a[i]!=a[i-1]) now++;
		else {
			ans=max(ans,now);
			now=1;
		}
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}

