#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,ans,x[60],y[60],dis[60][60];
signed main() {
	memset(dis,0x3f,sizeof dis);
	cin>>n;
	For(i,1,n) cin>>x[i]>>y[i];
	For(i,1,n) For(j,1,i) dis[i][j]=dis[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
	For(k,1,n) For(i,1,n) For(j,1,n) dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
	For(i,1,n) For(j,1,n) if(dis[i][j]<=2147483647) ans=max(ans,dis[i][j]);
	cout<<((ans+1)>>1);
	return 0;
}