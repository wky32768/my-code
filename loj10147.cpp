#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define Dow(i,a,b) for(register int i=a;i>=b;i--)
using namespace std;
int n,a[1200],sum[1200],mx[460][460],mn[460][460],ans1=0x3f3f3f3f,ans2=-0x3f3f3f3f;
signed main() {
	cin>>n;
	For(i,1,n*2) {
		if(i<=n) cin>>a[i];
		else a[i]=a[i-n];
		sum[i]=sum[i-1]+a[i];
	}
	memset(mn,0x3f3f3f3f,sizeof mn);
	memset(mx,-0x3f3f3f3f,sizeof mx);
	n*=2;
	For(i,1,n) mn[i][i]=mx[i][i]=0;
	Dow(i,n,1) For(j,i+1,n) For(k,i,j-1)	 {
		mn[i][j]=min(mn[i][j],mn[i][k]+mn[k+1][j]+sum[j]-sum[i-1]);
		mx[i][j]=max(mx[i][j],mx[i][k]+mx[k+1][j]+sum[j]-sum[i-1]);
	}
	For(i,1,n/2) {
		ans1=min(ans1,mn[i][i+n/2-1]);
		ans2=max(ans2,mx[i][i+n/2-1]);
	}
	cout<<ans1<<'\n'<<ans2;
	return 0;
}