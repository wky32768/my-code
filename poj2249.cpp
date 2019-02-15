#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,a[120];
signed main() {
	while(cin>>n && n) {
		memset(a,0,sizeof a);
		For(i,1,n) cin>>a[i];
		int dp[a[1]+1][a[2]+1][a[3]+1][a[4]+1][a[5]+1];
		memset(dp,0,sizeof dp);
		dp[0][0][0][0][0]=1;
		For(i,0,a[1]) For(j,0,a[2]) For(k,0,a[3]) For(l,0,a[4]) For(m,0,a[5]) {
			if(i<a[1]) dp[i+1][j][k][l][m]+=dp[i][j][k][l][m];
			if(j<a[2] && j<i) dp[i][j+1][k][l][m]+=dp[i][j][k][l][m];
			if(k<a[3] && k<j && k<i) dp[i][j][k+1][l][m]+=dp[i][j][k][l][m];
			if(l<a[4] && l<k && l<j && l<i) dp[i][j][k][l+1][m]+=dp[i][j][k][l][m];
			if(m<a[5] && m<l && m<k && m<j && m<i) dp[i][j][k][l][m+1]+=dp[i][j][k][l][m];
		}
		cout<<dp[a[1]][a[2]][a[3]][a[4]][a[5]]<<'\n';
	}
	return 0;
}
