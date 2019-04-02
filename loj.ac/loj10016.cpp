#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int t;
double H,h,d,ans;
double f(double x) {
	return H-(H-h)*d/x+d-x;
}
signed main() {
	cin>>t;
	while(t--) {
		cin>>H>>h>>d;
		double l=(H-h)*d/H,r=d;
		while(r-l>1e-8) {
			double mid1=l+(r-l)/3,mid2=r-(r-l)/3;
			if (f(mid1) > f(mid2)) r = mid2;
            else l = mid1;
		}
		printf("%.3lf\n",f(l));
	}
	return 0;
}