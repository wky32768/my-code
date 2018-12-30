#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
struct node {
	int x,y,z;
} a[120000];
int n,h,ans,b[120000];
bool cmp(node a,node b) {
	return a.y<b.y;
}
signed main() {
	cin>>n>>h;
	For(i,1,h) cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+h+1,cmp);
	for(int i=1;i<=n;i++) {
		int sum=0;
		For(j,a[i].x,a[i].y) if(b[j]) sum++;
		if(a[i].z<=sum) continue;
		for(int j=a[i].y;j>=a[i].x;j--) {
			if(!b[j]) {
				b[j]=1;
				ans++;
				sum++;
				if(sum==a[i].z) break;
			}
		} 
	}
	cout<<ans;
	return 0;
}

