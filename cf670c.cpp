#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
map <int,int> mp;
int a[560000],b[560000],n,m,ans;
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		mp[x]++;
	}
	cin>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	pair <int,int> tot,now;
	tot=make_pair(-0x3f,-0x3f);
	for(int i=1;i<=m;i++) {
		now=make_pair(mp[a[i]],mp[b[i]]);
		if(now>tot) {
			tot=now;
			ans=i;	
		}
	}
	cout<<ans;
}

