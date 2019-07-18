#include <bits/stdc++.h>
#define int long long
using namespace std;
int read() {
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
const int mod=1<<23;
const int N=120000;
int t,n,k,ans,C[120000][25];
int solve(int n,int k) {
	int ans=0ll;
	for(register int i=1; i<=min(23ll,k); i++) {
		ans=(ans+C[n][i]*i%mod*(1<<(i-1))%mod)%mod;
	}
	return ans;
}
signed main() {
	cin>>t;
	for(int i=0;i<=110000;i++) {
		C[i][0]=1;
		for(int j=1;j<=min(i,23ll);j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;	
	}
	while(t--) {
		n=read(),k=read();
		cout<<solve(n,k);
		puts("");
	}
	return 0;
}
/*
逆元只有在a与mod互质的时候才能用 
*/
