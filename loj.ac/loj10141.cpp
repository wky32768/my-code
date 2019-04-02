//好像唯一会打的长一点的就是树剖了。。。
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=120000;
int n,m,siz,tot,cnt,x,y,z;
int head[N<<1],sz[N],depth[N],top[N],mp[N],fa[N][18],w[N],ww=0;
bool vis[N];
char ch[12];
struct node {
	int l,r,lc,rc,s,tag;
} tree[N<<2];
//l,r:左右端点，lc,rc:左右的颜色，s:总颜色数，tag：修改标记
struct edge {
	int next,to;
} sxd[N<<1];
int read() {
	int f=0;
	char ch=getchar();
	while(!(ch>='0' && ch<='9')) ch=getchar();
	while(ch>='0' && ch<='9') {
		f=f*10+ch-'0';
		ch=getchar();
	}
	return f;
}
void write(int x) {
	if(x>=10) write(x/10);	
	putchar(x%10+'0');
}
void add(int u,int v) {
	sxd[++cnt].next=head[u];
	sxd[cnt].to=v;
	head[u]=cnt;
}
void dfs1(int at) {
	sz[at]=vis[at]=1;
	for(int i=1; i<=17; i++) {
		if(depth[at]<(1<<i)) break;
		fa[at][i]=fa[fa[at][i-1]][i-1];
	}
	for(int i=head[at]; i; i=sxd[i].next) {
		if(vis[sxd[i].to]) continue;
		depth[sxd[i].to]=depth[at]+1;
		fa[sxd[i].to][0]=at;
		dfs1(sxd[i].to);
		sz[at]+=sz[sxd[i].to];
	}
}
void dfs2(int at,int tp) {
	mp[at]=++tot;
	top[at]=tp;
	int heavy=0;
	for(int i=head[at]; i; i=sxd[i].next) if(depth[sxd[i].to]>depth[at] && sz[heavy]<sz[sxd[i].to]) heavy=sxd[i].to;
	if(!heavy) return;
	dfs2(heavy,tp);
	for(int i=head[at]; i; i=sxd[i].next) if(depth[sxd[i].to]>depth[at] && sxd[i].to!=heavy) dfs2(sxd[i].to,sxd[i].to);
}
int lca(int x,int y) {
	if(depth[x]<depth[y]) swap(x,y);
	int cha=depth[x]-depth[y];
	for(int i=17; i>=0; i--) if(cha&(1<<i)) x=fa[x][i];
	if(x==y) return x;
	for(int i=17; i>=0; i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void build(int rt,int l,int r) {
	tree[rt]=(node) {
		l,r,0,0,1,-1
	};
	if(l==r) return;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
}
void upd(int rt) {
	tree[rt].lc=tree[rt<<1].lc,tree[rt].rc=tree[rt<<1|1].rc;
	if(tree[rt<<1].rc!=tree[rt<<1|1].lc) tree[rt].s=tree[rt<<1].s+tree[rt<<1|1].s;
	else tree[rt].s=tree[rt<<1].s+tree[rt<<1|1].s-1;
}
void pushdown(int rt) {
	if(tree[rt].tag==-1 || tree[rt].l==tree[rt].r) return;
	tree[rt<<1].s=tree[rt<<1|1].s=1;
	tree[rt<<1].tag=tree[rt<<1|1].tag=tree[rt<<1].lc=tree[rt<<1].rc=tree[rt<<1|1].lc=tree[rt<<1|1].rc=tree[rt].tag;
	tree[rt].tag=-1;
}
void change(int rt,int l,int r,int C) {
	pushdown(rt);
	if(tree[rt].l==l && tree[rt].r==r) {
		tree[rt].lc=tree[rt].rc=tree[rt].tag=C;
		tree[rt].s=1;
		return;
	}
	int mid=(tree[rt].l+tree[rt].r)>>1;
	if(mid>=r) change(rt<<1,l,r,C);
	else if(mid<l) change(rt<<1|1,l,r,C);
	else change(rt<<1,l,mid,C),change(rt<<1|1,mid+1,r,C);
	upd(rt);
}
int getsum(int rt,int l,int r) {
	pushdown(rt);
	if(tree[rt].l==l && tree[rt].r==r) return tree[rt].s;
	int mid=(tree[rt].l+tree[rt].r)>>1;
	if(mid>=r) return getsum(rt<<1,l,r);
	else if(mid<l) return getsum(rt<<1|1,l,r);
	else {
		int tmp=1;
		if(tree[rt<<1].rc^tree[rt<<1|1].lc) tmp=0;
		return getsum(rt<<1,l,mid)+getsum(rt<<1|1,mid+1,r)-tmp;
	}
}
int getcolor(int rt,int which) {
	pushdown(rt);
	if(tree[rt].l==tree[rt].r) return tree[rt].lc;
	int mid=(tree[rt].l+tree[rt].r)>>1;
	if(which<=mid) return getcolor(rt<<1,which);
	else return getcolor(rt<<1|1,which);
}
int solvesum(int x,int y) {
	int ans=0;
	while(top[x]!=top[y]) {
		ans+=getsum(1,mp[top[x]],mp[x]);
		if(getcolor(1,mp[top[x]])==getcolor(1,mp[fa[top[x]][0]])) ans--;
		x=fa[top[x]][0];
	}
	ans+=getsum(1,mp[y],mp[x]);
	return ans;
}
void solvechange(int x,int y,int C) {
	while(top[x]!=top[y]) {
		change(1,mp[top[x]],mp[x],C);
		x=fa[top[x]][0];
	}
	change(1,mp[y],mp[x],C);
}
signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++) w[i]=read();
	for(int i=1; i<=n-1; i++) {
		x=read();
		y=read();
		add(x,y),add(y,x);
	}
	dfs1(1);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1; i<=n; i++) change(1,mp[i],mp[i],w[i]);
	int debug=0;
	for(int i=1; i<=m; i++) {
		scanf("%s",ch);
		if(ch[0]=='Q') {
			debug++;
			if(debug==22) ww=1;
			x=read();
			y=read();
			write(solvesum(x,lca(x,y))+solvesum(y,lca(x,y))-1);
			puts("");
		} else {
			x=read();
			y=read();
			z=read();
			solvechange(x,lca(x,y),z),solvechange(y,lca(x,y),z);
		}
	}
	return 0;
}
//调试90min