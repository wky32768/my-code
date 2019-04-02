#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,k,a[120000];
inline int read() {
    register int x=0,f=1;
    register char ch=getchar();
    while(!(ch>='0' && ch<='9')) {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
double b[120000],summ[120000];
double ans=0;
bool ok(double x) {
	summ[0]=0;
	For(i,1,n) {
		b[i]=(double)a[i]-x;
		summ[i]=summ[i-1]+b[i];
	}
	double mx=-1e10,mn=1e10;
	For(i,k,n) {
		mn=min(mn,summ[i-k]);
		mx=max(summ[i]-mn,mx);	
	}
	return mx>=0.0;
}
signed main() {
	cin>>n>>k;
	For(i,1,n) {
		a[i]=read();
	}
	double l=-1e6,r=1e6;
	while(r-l>1e-5) {
		double mid=(l+r)/2;
//		cout<<mid<<" "<<ok(mid)<<'\n';
		if(ok(mid)) {
			l=mid;
		} else r=mid;
	}
//	cout<<ans<<'\n';
//cout<<r<<'\n';
	r*=1000;
	cout<<(int)r<<'\n';
}

