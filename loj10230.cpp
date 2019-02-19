//对公的结尾的方案数，取前缀和
//sum只全是母的，因为后来计算时加了一个公的，所以互不一样
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=5000011;
int sum[120000],dp[120000],x,n,k;
signed main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++) dp[i]=1;
	for(int i=1;i<=n;i++) {
		if(i>k) dp[i]=(dp[i]+sum[i-k-1])%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	cout<<(sum[n]+1)%mod;
	return 0;
}