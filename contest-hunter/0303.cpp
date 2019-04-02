#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m;
vector <int> q;
bool vis[12];
void dfs(int at) {
	if(at>n) {
		for(int i=0; i<q.size(); i++) cout<<q[i]<<" ";
		puts("");
		return;
	}
	for(int i=1;i<=n;i++) if(!vis[i]) {
		q.push_back(i);
		vis[i]=1;
		dfs(at+1);
		vis[i]=0;
		q.pop_back();	
	}
}
signed main() {
	cin>>n;
	dfs(1);
	return 0;
}

