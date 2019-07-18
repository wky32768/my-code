#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int read() {
	int x = 0, f = 0;
	char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}
const int N = 230000;
struct node {
	int next,to;
} e[N<<1];
vector <int> pfy[N];
int n, m, q, x, y, nn,cnt1,cnt2;
int head1[N],head2[N],dfn[N], low[N], lian[N], tot_kuai, belong[N], bian1[N], bian2[N];
bool vis[N];
stack<int> st;
void add1(int u,int v) {
	e[++cnt1].next=head1[u];
	e[cnt1].to=v;
	head1[u]=cnt1;
}
void tarjan(int x, int f) {//注意是边双（显然是我写成了点双然后各种爆蛋 
	//接的是边，显然缩的时候会把桥拎出来啊
	dfn[x] = low[x] = ++dfn[0];
	lian[x] = lian[0]; //联通块（
	st.push(x);
	vis[x] = 1;
	for(int i=head1[x]; i; i=e[i].next) {
		int now = e[i].to;
		if((i^1)==f) continue;
		if (!dfn[now]) {
			tarjan(now,i);
			low[x] = min(low[x], low[now]);
		} else if (vis[now])
			low[x] = min(low[x], dfn[now]);
	}
	if (dfn[x] == low[x]) {
		tot_kuai++;
		int sxd = 0;
		while (sxd != x && !st.empty()) {
			sxd = st.top();
			st.pop();
			belong[sxd] = tot_kuai;
			vis[sxd] = 0;
		}
	}
}
int depth[N], fa[N][21],up[N],down[N];
void dfs1(int x) {
	For(i, 1, 20) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	For(i, 0, pfy[x].size() - 1) {
		int now = pfy[x][i];
		if (now == fa[x][0])
			continue;
		fa[now][0] = x;
		depth[now] = depth[x] + 1;
		dfs1(now);
	}
}
int lca(int x, int y) {
	if (depth[x] < depth[y])
		swap(x, y);
	for (int i = 20; i >= 0; i--)
		if (depth[fa[x][i]] >= depth[y])
			x = fa[x][i];
	if (x == y)
		return x;
	for (int i = 20; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
void dfs2(int x) {
	vis[x]=1;
	For(i,0,pfy[x].size()-1) {
		int now=pfy[x][i];
		if(vis[now]) continue;
		dfs2(now);
		up[x]+=up[now],down[x]+=down[now];//这里可以把Up和down都当做从下往上，因为他们的前缀和表示是相同的
	}
}
void solve() {
	n=tot_kuai;
	For(i, 1, n) {
		if (!depth[i]) {
			depth[i] = 1;
			dfs1(i);
		}
	}
	For(i,1,q) {
		x=read(),y=read();
		if(lian[x]!=lian[y]) {
			puts("No");
			return;
		}
		x=belong[x],y=belong[y];
		up[x]++,up[lca(x,y)]--;//都是前缀和
		down[y]++,down[lca(x,y)]--;
	}
	memset(vis,0,sizeof vis);
	For(i,1,n) if(!vis[i]) dfs2(i);//按联通块更新每一个数的值
	For(i,1,n) if(up[i] && down[i]) {
		puts("No");
		return;
	}
	puts("Yes");
}
signed main() {
	n = read(), m = read(), q = read();
	cnt1=1;
	For(i, 1, m) {
		x = read(), y = read();
		bian1[i] = x, bian2[i] = y;
		add1(x,y),add1(y,x);
	}
	For(i, 1, n) if (!dfn[i]) {
		lian[0]++;
		tarjan(i, 0);
	}
	For(i, 1, m) if (belong[bian1[i]] != belong[bian2[i]]) {
		pfy[belong[bian1[i]]].push_back(belong[bian2[i]]);
		pfy[belong[bian2[i]]].push_back(belong[bian1[i]]);
	}
	nn = tot_kuai;
	solve();
}
