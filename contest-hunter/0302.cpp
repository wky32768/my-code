#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m;
vector <int> q;
void dfs(int at) {
	if(at>n) {
		if(q.size()!=m) return;
		for(int i=0; i<q.size(); i++) cout<<q[i]<<" ";
		puts("");
		return;
	}
	if(q.size()<m) {
		q.push_back(at);
		dfs(at+1);
		q.pop_back();
	}
	dfs(at+1);
}
signed main() {
	cin>>n>>m;
	dfs(1);
	return 0;
}

