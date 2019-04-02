#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,ans,a[3200],b[3200],f[3200][3200];
signed main() {
	cin>>n;
	For(i,1,n) cin>>a[i];
	For(i,1,n) cin>>b[i];
	For(i,1,n) {
		int mx=0;//前面dp[i-1][k]的最大值
		For(j,1,n) {
			if(a[i]==b[j]) f[i][j]=mx+1;
			else f[i][j]=f[i-1][j];
			if(a[i]>b[j]) mx=max(mx,f[i-1][j]);//做后一个(a[i])的前一个，就必须要比a[i]更小
			ans=max(ans,f[i][j]);
		}
	}	
	cout<<ans;
	return 0;
}