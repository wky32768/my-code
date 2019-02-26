//感觉点分治和树上dp差不多？ 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=120000;
int n,m,cnt,rt,sum,top,x,y,z;
int f[N],sz[N],dis[N],a[N],head[N],tmp[N];
set <int> q;
bool ans[N],vis[N];
struct node {
	int next,to,w;
} sxd[N<<1];
void add(int u,int v,int w) {
	sxd[++cnt].next=head[u];
	sxd[cnt].to=v;
	sxd[cnt].w=w;
	head[u]=cnt;
}
void getrt(int x,int fa) {
	f[x]=0;
	sz[x]=1;
	for(int i=head[x]; i; i=sxd[i].next) {
		if(sxd[i].to==fa || vis[sxd[i].to]) continue;
		getrt(sxd[i].to,x);
		sz[x]+=sz[sxd[i].to];
		f[x]=max(f[x],sz[sxd[i].to]);
	}
	f[x]=max(f[x],sum-sz[x]);
	if(f[x]<f[rt]) rt=x;
}
void dfs(int x,int fa) {
	tmp[++top]=dis[x];
	for(int i=head[x]; i; i=sxd[i].next) {
		if(sxd[i].to==fa || vis[sxd[i].to]) continue;
		dis[sxd[i].to]=dis[x]+sxd[i].w;
		dfs(sxd[i].to,x);
	}
}
void query(int x) {
	for(int i=1; i<=m; i++) if(!ans[i]) if(*q.lower_bound(a[i]-x)==a[i]-x) ans[i]=1;//是否在集合里出现过 
}
void solve(int x) {
	vis[x]=1;
	q.clear();
	q.insert(0);
	for(int i=head[x]; i; i=sxd[i].next) {
		if(vis[sxd[i].to]) continue;
		top=0;
		dis[sxd[i].to]=sxd[i].w;
		dfs(sxd[i].to,x);
		for(int j=1; j<=top; j++) query(tmp[j]);
		for(int j=1; j<=top; j++) q.insert(tmp[j]);
	}//计算经过根节点的情况下的解 
	for(int i=head[rt]; i; i=sxd[i].next) {
		if(vis[sxd[i].to]) continue;
		rt=0,sum=sz[sxd[i].to];
		getrt(sxd[i].to,0);
		solve(rt);
	}//对于子节点递归求解 
}
signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<n; i++) {
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1; i<=m; i++) cin>>a[i];
	sum=n;
	f[0]=n+1;
	getrt(1,0);
	solve(rt);
	for(int i=1; i<=m; i++) {
		if(ans[i]) puts("AYE");
		else puts("NAY");
	}
	return 0;
}
