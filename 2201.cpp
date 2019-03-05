#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,k,ans,bag[1200],w[1200];
bool cmp(int a,int b) {
	return a>b;
}
void dfs(int at,int tot) {//第几只猫，有几辆车
	if(tot>=ans) return;
	if(at>n) {
		ans=min(ans,tot);
		return;
	}
	For(i,1,tot) if(bag[i]+w[at]<=k) {
		bag[i]+=w[at];
		dfs(at+1,tot);
		bag[i]-=w[at];
	}
	bag[tot+1]=w[at];
	dfs(at+1,tot+1);
	bag[tot+1]=0;
}
signed main() {
	scanf("%lld%lld",&n,&k);
	For(i,1,n) scanf("%lld",&w[i]);
	sort(w+1,w+n+1,cmp);
	ans=n;
	dfs(1,0);
	printf("%lld",ans);
}

