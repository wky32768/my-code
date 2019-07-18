#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int read() {
	int x = 0, f = 0;
	char ch = getchar();
	while (!isdigit(ch))
		f |= (ch == '-'), ch = getchar();
	while (isdigit(ch))
		x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}
const int N = 120000;
vector<int> q[100005];
map<pair<int, int>, bool> mp;
int d, n, ru[N], ans[N], m, x, y,cnt;
priority_queue <int> xd;
bool vis[N];
void tuopu() {
	while(!xd.empty()) xd.pop();
	memset(vis,0,sizeof vis);
	int now=0;
	For(i,1,n) if(ru[i]==0) xd.push(i);
	while(!xd.empty()) {
		int x=xd.top();
		xd.pop();
		ans[++cnt]=x;
//		cout<<"x="<<x<<'\n';
		vis[x]=1;
		if(!q[x].empty()) For(i,0,q[x].size()-1) {
			ru[q[x][i]]--;
			if(ru[q[x][i]]==0) xd.push(q[x][i]);
		}
	}
	if(cnt!=n) puts("Impossible!");
	else {
		for(int i=cnt; i>=1; i--) cout<<ans[i]<<" ";
		puts("");
	}
}
signed main() {
	d = read();
	while (d--) {
		memset(ru, 0, sizeof ru);
		For(i,1,100000) q[i].clear();
		mp.clear();
		cnt=0;

		n = read(), m = read();
		while (m--) {
			x = read(), y = read();
			if(mp[make_pair(x,y)]==1) continue;
			q[y].push_back(x);
			ru[x]++;
			mp[make_pair(x,y)]=1;
		}
		tuopu();
	}
	return 0;
}
