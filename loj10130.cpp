#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m,x,y,cnt,head[1200000],fa[520000][25],depth[520000]; 
struct node {int next,to;} sxd[1200000];
void add(int u,int v) {
	sxd[++cnt].next=head[u];
	sxd[cnt].to=v;
	head[u]=cnt;
}
//下面的要默写
void dfs(int at,int f) {
	depth[at]=depth[f]+1;
	fa[at][0]=f;
	for(int i=1;(1<<i)<=depth[at];i++) fa[at][i]=fa[fa[at][i-1]][i-1];
	for(int i=head[at];i;i=sxd[i].next) {
		if(sxd[i].to==f) continue;
		dfs(sxd[i].to,at);
	}
} 
int lca(int x,int y) {
	if(depth[x]>depth[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(depth[x]<=depth[y]-(1<<i)) y=fa[y][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--) if(fa[x][i]!=fa[y][i]) {
		x=fa[x][i];
		y=fa[y][i];
	}
	return fa[x][0];
}
//上面的要默写
signed main() {
	cin>>n;
	For(i,1,n-1) {
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	cin>>m;
	while(m--) {
		cin>>x>>y;
		cout<<depth[x]+depth[y]-depth[lca(x,y)]*2<<'\n';
	}
	return 0;
}