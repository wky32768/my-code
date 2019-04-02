//感觉点分治和树上dp差不多？
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=120000;
int n,k,cnt,rt,sum,top,x,y,z,ans;
int f[N],sz[N],dis[N],a[N],head[N],tmp[N];
set <int> q;
bool vis[N];
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
	tmp[++tmp[0]]=dis[x];
	for(int i=head[x];i;i=sxd[i].next) {
		if(vis[sxd[i].to] || sxd[i].to==fa) continue;
		dis[sxd[i].to]=dis[x]+sxd[i].w;
		dfs(sxd[i].to,x);
	}
}
int calc(int x,int now) {
	dis[x]=now;
	tmp[0]=0;
	dfs(x,0);
	sort(tmp+1,tmp+tmp[0]+1);
	int t=0,l=1,r=tmp[0];
	while(l<r) {
		if(tmp[l]+tmp[r]<=k) t+=r-l,l++;
		else r--;
	}
	return t;
}
void solve(int x) {
	ans+=calc(x,0);
	vis[x]=1;
	for(int i=head[x];i;i=sxd[i].next) {
		if(vis[sxd[i].to]) continue;
		ans-=calc(sxd[i].to,sxd[i].w);
		sum=sz[sxd[i].to];
		rt=0;
		getrt(sxd[i].to,0);
		solve(rt);
	}
}
signed main() {
	while(scanf("%lld%lld",&n,&k) && n) {
		memset(head,0,sizeof head);
		memset(vis,0,sizeof vis);
		cnt=0;
		rt=0;
		ans=0;
		for(int i=1; i<n; i++) {
			scanf("%lld%lld%lld",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}
		sum=n;
		f[0]=0x3f3f3f3f;
		getrt(1,0);
		solve(rt);
		cout<<ans<<'\n';
	}
	return 0;
}