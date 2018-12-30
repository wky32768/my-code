#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> q;
void dfs(int at) {
	if(at>n) {
		for(int i=0;i<q.size();i++) cout<<q[i]<<" ";
		cout<<'\n';
		return;
	}
	dfs(at+1);
	q.push_back(at);
	dfs(at+1);
	q.pop_back();
}
signed main() {
	cin>>n;
	dfs(1);
}
