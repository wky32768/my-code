#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int t,n,a[120000],b[120000],c[120000];
double l,r,mid,ans,mn=2147483647;
double f(double x) {
	double mx=a[1]*x*x+b[1]*x+c[1];
	For(i,2,n) mx=max(a[i]*x*x+b[i]*x+c[i],mx);
	return mx;
}
signed main() {
	cin>>t;
	while(t--) {
		cin>>n;
		For(i,1,n) cin>>a[i]>>b[i]>>c[i];
		l=0,r=1000;
		while(r-l>1e-11) {
			double mid1=l+(r-l)/3,mid2=l+(r-l)/3*2;
			if(f(mid1)<f(mid2)) r=mid2;
			else l=mid1;
		}
		printf("%.4lf\n",f(l));
	}
	return 0;
}