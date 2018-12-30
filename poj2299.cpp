#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int a[560000],b[560000],ni,n;
void merge(int l,int r) {
	int mid=(l+r)>>1;
	if(l==r) return;
	merge(l,mid);
	merge(mid+1,r);
	int x=l,y=mid+1;
	For(i,l,r) {
		if(y>r || (x<=mid && a[x]<a[y])) b[i]=a[x++];
		else b[i]=a[y++],ni+=mid-x+1;
	}
	For(i,l,r) a[i]=b[i];
}
signed main() {
	while(cin>>n && n) {
		For(i,1,n) cin>>a[i];
		ni=0;
		merge(1,n);	
		cout<<ni<<'\n';
	}
	return 0;
}

