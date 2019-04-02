#include <bits/stdc++.h>
#define int long long
using namespace std;
set <pair <int,int> > q;
int n,x;
signed main() {
	cin>>n>>x;
	q.insert(make_pair(x,1));
	for(int i=2;i<=n;i++) {
		cin>>x;
		q.insert(make_pair(x,i));
		set <pair <int,int> > :: iterator it=q.find(make_pair(x,i));
		pair <int,int> ans;
		ans.first=0x3f3f3f3f;
		if(++it!=q.end()) ans=make_pair((*it).first-x,(*it).second);
		it--;
		if(it--!=q.begin() && ans.first>=x-(*it).first) ans=make_pair(x-(*it).first,(*it).second);
		cout << ans.first << " " << ans.second << '\n';
	}
}
