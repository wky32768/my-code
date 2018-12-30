#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,w[23][23],f[1<<20][20];
signed main() {
	cin>>n;
	For(i,0,n-1) For(j,0,n-1) cin>>w[i][j];	
	memset(f,0x3f,sizeof f);
	f[1][0]=0;
	For(i,1,(1<<n)-1) For(j,0,n-1) if((i>>j) & 1) For(k,0,n-1) if((i>>k) & 1) f[i][j]=min(f[i][j],f[i^(1<<j)][k]+w[k][j]);
	cout<<f[(1<<n)-1][n-1];
	return 0;
}

