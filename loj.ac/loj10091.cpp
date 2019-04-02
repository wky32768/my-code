#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {
	int next, to;
} sxd[1200000];
int n, m, x, y, tot, cnt, ans, flag,num;
int head[1200000], vis[1200000], dfn[1200000],low[1200000],xx[1200000],yy[1200000],sum[1200000],belong[1200000],chu[1200000];
void add(int x, int y) {
	sxd[++cnt] = (node) {
		head[x], y
	};
	head[x] = cnt;
}
stack <int> q;
void tarjan(int at) {
	dfn[at] = low[at] = ++tot;
	vis[at] = 1;
	q.push(at);
	for (int i = head[at]; i; i = sxd[i].next) {
		if (!dfn[sxd[i].to]) {
			tarjan(sxd[i].to);
			low[at] = min(low[at], low[sxd[i].to]);
		} else if (vis[sxd[i].to]) {
			low[at] = min(low[at], low[sxd[i].to]);
		}
	}
	if (dfn[at] == low[at]) {
		num++;
		int now=0;
		while(now!=at) {
			now=q.top();
			q.pop();
			vis[now]=0;
			belong[now]=num;
			sum[num]++;
		}
	}
}
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		xx[i]=x,yy[i]=y;
		add(x, y); 
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for(int i=1;i<=m;i++) {
		if(belong[xx[i]]!=belong[yy[i]]) {
			chu[belong[xx[i]]]++;
		}
	}
	for(int i=1;i<=num;i++) {
		if(!chu[i]) {
			if(ans) flag=1;
			else ans=sum[i];
		}
	}
	if(flag) puts("0");
	else cout<<ans;
	return 0;
}