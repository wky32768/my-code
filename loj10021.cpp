#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,ans[120],a[120],mn;
void dfs(int x) {//第几层
	if(x-1>mn || a[x-1]>n) return;
	if(a[x-1]==n) {
		if(x-1>=mn) return;
		mn=x-1;
		For(i,1,mn) ans[i]=a[i];
		return;
	}
	for(register int j=x-1;j>=1;j--) if(a[x-1]+a[j]<=n) {
		a[x]=a[j]+a[x-1];
		dfs(x+1);
		a[x]=0;
	}
}
signed main() {
	while(cin>>n && n) {
		a[1]=1;
		mn=120;
		dfs(2);
		For(i,1,mn) cout<<ans[i]<<" ";
		puts("");
	}
	return 0;
}
