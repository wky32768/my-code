#include <bits/stdc++.h>
#define int long long
using namespace std;
map <int,int> mp;
inline int calc(int x) {
	if(x==1) return 0;
	else if(x==2) return 1;
	else if(mp[x]) return mp[x];
	int xx=calc(x>>1),yy=calc(x-(x>>1));
	mp[x]=xx+yy+x-1;
	return mp[x];  
}
int n;
signed main() {
	cin>>n;
	cout<<calc(n)<<'\n';
}
