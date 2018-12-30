#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n;
double l,r,a[120],ans;
double calc(double x) {
	double ans=0;
	for(int i=n;i>=0;i--) {
		ans*=x;
		ans+=a[i];
	}
	return ans;
}
signed main() {
	cin>>n>>l>>r;
	for(int i=n;i>=0;i--) cin>>a[i];
	int m=50;
	while(m--) {
		double mid1=l+(r-l)/3;	
		double mid2=l+(r-l)*2/3;
		if(calc(mid1)<calc(mid2)) l=mid1;
		else if(calc(mid1)>calc(mid2)) r=mid2;
	}
	printf("%.5lf",l);
	return 0;
}

