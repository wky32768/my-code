#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,k,ans;
void dfs(int now,int tot,int big) {
	if(now==k && tot==n) {
		ans++;
		return;
	}
	if(now==k-1) {
		if(big<=n-tot) ans++;
		return;
	}
	if(tot>n || now>k) return;
	For(i,big,n-tot) {
		dfs(now+1,tot+i,i);
	} 
}
signed main() {
	cin>>n>>k;
	dfs(0,0,1);
	cout<<ans;
	return 0;
}