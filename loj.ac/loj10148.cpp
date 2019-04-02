#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define Dow(i,a,b) for(register int i=a;i>=b;i--)
using namespace std;
int n,a[1200],sum[1200],mx[460][460],ans=-0x3f3f3f3f;
signed main() {
	cin>>n;
	For(i,1,n) cin>>a[i];	
	For(i,n+1,2*n) a[i]=a[i-n];
	memset(mx,-0x3f3f3f3f,sizeof mx);
	n*=2;
	For(i,1,n) mx[i][i]=0;
	for(int i=n;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			for(int k=i;k<j;k++) {
				mx[i][j]=max(mx[i][j],mx[i][k]+mx[k+1][j]+a[i]*a[k+1]*a[j+1]);
			}
	For(i,1,n) ans=max(ans,mx[i][i+n/2-1]);
	cout<<ans;
	return 0;
}