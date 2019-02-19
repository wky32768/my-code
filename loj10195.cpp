#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m,k,x,mod,tot,xx;
bool vis[1200000];
int ksm(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
signed main() {
	cin>>n>>m>>k>>x;
	xx=x;
	while(!vis[x]) {
		vis[x]=1;
		x=(x+m)%n;
		mod++;
	}
	tot=ksm(10,k);
	For(i,1,tot) xx=(xx+m)%n;	
	cout<<xx;
	return 0;
}