#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
char a[120000];
int n,dp[120][120];
bool ok(int x,int y) {
	return (a[x]=='(' && a[y]==')') || (a[x]=='[' && a[y]==']');
}
signed main() {
	scanf("%s",a+1);
	n=strlen(a+1);
	For(i,1,n) dp[i][i]=1;
	For(len,1,n-1) for(int l=1;l+len<=n;l++) {
		int r=l+len;
		dp[l][r]=0x3f3f3f3f;
		For(k,l,r-1) dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
		if(ok(l,r)) dp[l][r]=min(dp[l][r],dp[l+1][r-1]);
	}
	cout<<dp[1][n];
	return 0;
}