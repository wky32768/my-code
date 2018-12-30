#include <bits/stdc++.h>
#define int long long
using namespace std;
struct cow {
	int x,y;
}a[120000],b[120000];
int n,c,ans;
bool vis[120000];
bool cmp1(cow a,cow b) {
	return a.x>b.x;
}
bool cmp2(cow a,cow b) {
	return a.x>b.x;
}
signed main() {
	cin>>n>>c;
	for(int i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].y;
	} 
	for(int i=1;i<=c;i++) {
		cin>>b[i].x>>b[i].y;
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+c+1,cmp2);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=c;j++) {
			if(b[j].y && a[i].x<=b[j].x && a[i].y>=b[j].x) {
				ans++;
				b[j].y--;
				break;
			}
		}
	}
	cout<<ans;
}