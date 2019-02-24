#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {
	int next, to;
} sxd[1200000];
int n, m, x, y, tot, cnt, ans, flag,num;
int head[1200000], vis[1200000], dfn[1200000],low[1200000],xx[1200000],yy[1200000],sum[1200000],belong[1200000],chu[1200000],ru[1200000];
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
		// cout<<"start\n";
		num++;
		int now=0;
		while(now!=at) {
			now=q.top();
			q.pop();
			vis[now]=0;
			// cout<<now<<'\n';
			belong[now]=num;
			sum[num]++;
		}
		// cout<<"end\n";
	}
}
signed main() {
	cin >> n;
	for(int i=1;i<=n;i++) {
		int x=0x3f3f3f3f;
		while(x!=0) {
			cin>>x;
			if(x==0) break;
			add(i,x);
			xx[cnt]=i;
			yy[cnt]=x;
		}
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for(int i=1;i<=cnt;i++) {
		if(belong[xx[i]]!=belong[yy[i]]) {
			chu[belong[xx[i]]]++;
			ru[belong[yy[i]]]++;
		}
	}
	int aa=0,bb=0;
	for(int i=1;i<=num;i++) {
		if(!ru[i]) aa++;
		if(!chu[i]) bb++;
	}
	if(num==1) cout<<"1\n0";
	else cout<<aa<<"\n"<<max(aa,bb);
	return 0;
}