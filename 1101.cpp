#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
vector <int> now,ans;
int n,cnt;
void dfs(int x) {
	if(x>n) {
		cnt++;
		if(cnt>20) exit(0);
		for(int i=0; i<ans.size(); i++) cout<<ans[i];
		for(int i=now.size()-1; i>=0; i--) cout<<now[i];
		cout<<'\n';
		return;
	}
	if(now.size()) {
		int num=now.back();
		now.pop_back();
		ans.push_back(num);
		dfs(x);
		now.push_back(num);
		ans.pop_back();
	}
	now.push_back(x);
	dfs(x+1);
	now.pop_back();
}
signed main() {
	cin>>n;
	dfs(1);
}

