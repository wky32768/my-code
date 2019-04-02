#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=650000;
int n,m,cnt,x,y,opt;
int siz[N],fa[N],son[N],top[N],w[N],head[N],a[N],tree[N<<2],add[N],mp[N];
struct node {int next,to;} sxd[N<<1];
void ad(int u,int v) {
	sxd[++cnt]=(node) {head[u],v};
	head[u]=cnt;
}
void dfs1(int at,int f) {
	int num=1,mx=0,mxat=0;
	for(int i=head[at];i;i=sxd[i].next) {
		if(sxd[i].to==f) continue;
		fa[sxd[i].to]=at;
		dfs1(sxd[i].to,at);
		num+=siz[sxd[i].to];
		if(siz[sxd[i].to]>mx) mx=siz[sxd[i].to],mxat=sxd[i].to;
	}
	siz[at]=num;
	son[at]=mxat;
}
void dfs2(int at) {
	a[++cnt]=w[at];
	mp[at]=cnt;
	if(son[at]) {
		top[son[at]]=top[at];
		dfs2(son[at]);
	}
	for(int i=head[at];i;i=sxd[i].next) {
		if(sxd[i].to==fa[at] || sxd[i].to==son[at]) continue;
		dfs2(sxd[i].to);
	}
}
void build(int rt,int l,int r) {
	if(l==r) {
		tree[rt]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void pushdown(int rt,int l,int r) {
	if(add[rt]) {
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		tree[rt<<1]+=add[rt]*l;
		tree[rt<<1|1]+=add[rt]*r;
		add[rt]=0;
	}
}
void change(int L,int R,int C,int l,int r,int rt) {
	if(L<=l && r<=R) {
		add[rt]+=C;
		tree[rt]+=C*(r-l+1);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(rt,mid-l+1,r-mid);
	if(L<=mid) change(L,R,C,l,mid,rt<<1);
	if(R>mid) change(L,R,C,mid+1,r,rt<<1|1);
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
int he(int L,int R,int l,int r,int rt) {
	if(L<=l && r<=R) return tree[rt];
	int mid=(l+r)>>1,ans=0;
	pushdown(rt,mid-l+1,r-mid);
	if(L<=mid) ans+=he(L,R,l,mid,rt<<1);
	if(R>mid) ans+=he(L,R,mid+1,r,rt<<1|1);
	return ans;
}
int all_he(int x) {
	int ans=0;
	while(top[x]!=1) {
		ans+=he(mp[top[x]],mp[x],1,n,1);
		x=fa[top[x]];
	}
	ans+=he(mp[top[x]],mp[x],1,n,1);
	return ans;
}
signed main() {
	cin>>n>>m;
	For(i,1,n) cin>>w[i];
	For(i,1,n-1) {
		cin>>x>>y;
		ad(x,y),ad(y,x);
	}
	dfs1(1,0);
	cnt=0;
	For(i,1,n) top[i]=i;
	dfs2(1);
	build(1,1,n);
	For(i,1,m) {
		cin>>opt;
		if(opt==1) {
			cin>>x>>y;
			change(mp[x],mp[x],y,1,n,1);
		} else if(opt==2) {
			cin>>x>>y;
			change(mp[x],mp[x]+siz[x]-1,y,1,n,1);
		} else if(opt==3) {
			cin>>x;
			cout<<all_he(x)<<'\n';
		}
	}
	return 0;
}
