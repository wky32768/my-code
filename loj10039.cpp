#include <bits/stdc++.h>
#define int unsigned long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,cnt,mx;
int a[1200000],f1[1200000],f2[1200000],p[1200000],ans[1200000];
int solve(int x) {
	set <int> q;
	for(int l=1;l+x-1<=n;l+=x) {
		int r=l+x-1;
		q.insert(min(f1[r]-f1[l-1]*p[r-l+1],f2[l]-f2[r+1]*p[r-l+1]));
	}
	return q.size();
}
signed main() {
	cin>>n;
	p[0]=1;
	For(i,1,n) cin>>a[i];
	For(i,1,n) f1[i]=f1[i-1]*13131+a[i],p[i]=p[i-1]*13131;
	for(int i=n;i>=1;i--) f2[i]=f2[i+1]*13131+a[i];
	For(i,1,n) {
		int w=solve(i);
		if(w>mx) {
			mx=w;
			cnt=0;
			ans[++cnt]=i;
		} else if(w==mx) ans[++cnt]=i;
	}
	cout<<mx<<" "<<cnt<<'\n';	
	For(i,1,cnt) cout<<ans[i]<<" ";
	return 0;
}