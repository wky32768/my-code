#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=500;
set <int> q[N];
vector <pair <int,int> > ans;
int t,n,m,x,y,tot;
void dfs(int x) {
	if(q[x].empty()) return;
	int sxd=*q[x].begin();
	q[x].erase(sxd);
	q[sxd].erase(x);
	if(sxd!=n+1 && x!=n+1) {
		ans.push_back(make_pair(sxd,x));
	}
	dfs(sxd);
}
void euler() {
	cout<<n-q[n+1].size()<<'\n';//只有偶点能够使其出入度相等
	For(i,1,n) if(!q[i].empty()) dfs(i);
	if(!ans.empty())For(i,0,ans.size()-1) cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}
signed main() {
	cin>>t;
	while(t--) {
		ans.clear();
		For(i,1,N-1) q[i].clear();
		cin>>n>>m;
		For(i,1,m) {
			cin>>x>>y;
			q[x].insert(y);
			q[y].insert(x);
		}
		For(i,1,n) if(!q[i].empty())if(q[i].size()%2==1) {
				q[n+1].insert(i);
				q[i].insert(n+1);
			}
		euler();
	}
}
