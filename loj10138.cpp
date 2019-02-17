#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=120000;
int n,q,tot,cnt,x,y;
int tpos[N],pre[N],a[N<<2],head[N],sz[N],wson[N],fa[N],d[N],top[N],sumv[N<<2],maxv[N<<2];
char ch[12];
struct edge {int u,v,next;} g[N];
void add(int u,int v) {
	g[++tot]=(edge) {u,v,head[u]};
	head[u]=tot;	
}
void dfs1(int at,int f) {
	sz[at]=1;
	for(int i=head[at];i;i=g[i].next) {
		if(g[i].v==f) continue;
		d[g[i].v]=d[at]+1;
		fa[g[i].v]=at;
		dfs1(g[i].v,at);
		sz[at]+=sz[g[i].v];
		if(sz[g[i].v]>sz[wson[at]]) wson[at]=g[i].v;
	}
}
void dfs2(int at,int tp) {
	tpos[at]=++cnt;
	pre[cnt]=at;
	top[at]=tp;
	if(wson[at]) dfs2(wson[at],tp);
	for(int i=head[at];i;i=g[i].next) {
		if(g[i].v==fa[at] || g[i].v==wson[at]) continue;
		dfs2(g[i].v,g[i].v);
	}
}
void pushup(int rt) {
	sumv[rt]=sumv[rt<<1]+sumv[rt<<1|1];
	maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
}
void build(int rt,int l,int r) {
	if(l==r) {
		sumv[rt]=maxv[rt]=a[pre[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int which,int C,int l,int r,int rt) {
	if(l==r) {
		sumv[rt]=maxv[rt]=C;
		return;
	}
	int mid=(l+r)>>1;
	if(which<=mid) update(which,C,l,mid,rt<<1);
	if(which>mid) update(which,C,mid+1,r,rt<<1|1);
	pushup(rt);
}
int he(int L,int R,int l,int r,int rt) {
	if(L<=l && r<=R) return sumv[rt];
	int mid=(l+r)>>1,ans=0;
	if(L<=mid) ans+=he(L,R,l,mid,rt<<1);
	if(R>mid) ans+=he(L,R,mid+1,r,rt<<1|1);
	pushup(rt);
	return ans;
}
int mx(int L,int R,int l,int r,int rt) {
	if(L<=l && r<=R) return maxv[rt];
	int mid=(l+r)>>1,ans=-0x3f3f3f3f;
	if(L<=mid) ans=max(ans,mx(L,R,l,mid,rt<<1));
	if(R>mid) ans=max(ans,mx(L,R,mid+1,r,rt<<1|1));
	pushup(rt);
	return ans;
}
int qsum(int u,int v) {
	int ans=0;
	while(top[u]!=top[v]) {
		if(d[top[u]]<d[top[v]]) swap(u,v);
		ans+=he(tpos[top[u]],tpos[u],1,n,1);
		u=fa[top[u]];
	}
	if(d[u]<d[v]) swap(u,v);
	ans+=he(min(tpos[u],tpos[v]),max(tpos[u],tpos[v]),1,n,1);
	return ans;
}
int qmax(int u,int v) {
	int ans=-0x3f3f3f3f;
	while(top[u]!=top[v]) {
		if(d[top[u]]<d[top[v]]) swap(u,v);
		ans=max(ans,mx(tpos[top[u]],tpos[u],1,n,1));
		u=fa[top[u]];
	}
	if(d[u]<d[v]) swap(u,v);
	ans=max(ans,mx(min(tpos[u],tpos[v]),max(tpos[u],tpos[v]),1,n,1));
	return ans;
}
signed main() {
	cin>>n;
	For(i,1,n-1) {
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	For(i,1,n) cin>>a[i];
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	cin>>q;
	while(q--) {
		cin>>ch>>x>>y;
		if(ch[1]=='H') update(tpos[x],y,1,n,1);
		if(ch[1]=='M') cout<<qmax(x,y)<<'\n';
		if(ch[1]=='S') cout<<qsum(x,y)<<'\n';
	}
	return 0;
}