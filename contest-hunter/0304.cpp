#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int a[120000],n,mx,mn;
signed main() {
	cin>>n;
	For(i,1,n) cin>>a[i];
	For(i,2,n) {
		if(a[i]>a[i-1]) mx+=a[i]-a[i-1];
		else mn+=a[i-1]-a[i];
	}
	cout<<max(mx,mn)<<'\n'<<abs(mx-mn)+1;
}

