#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,ans=1;
struct node {
	int x,y;
	friend bool operator < (node a,node b) {
		if(a.y!=b.y) return a.y<b.y;
		else return a.x<b.x;
	}
} mcl[1200];
signed main() {
	cin>>n;
	For(i,1,n) cin>>mcl[i].x>>mcl[i].y;
	sort(mcl+1,mcl+n+1);
	int last=mcl[1].y;
	For(i,1,n) {
		if(mcl[i].x>=last) {
			ans++;
			last=mcl[i].y;
		}
	}
	cout<<ans;
	return 0;
}

