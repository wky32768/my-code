#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int read() {
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch))f|=(ch=='-'),ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
const int N=3000005;
int head[N<<1],cnt,n,m,depth[N],fa[100005][21],num[N],x,y,tot,tree[N<<2],ls[N<<2],rs[N<<2],ans[N],rt[N];
struct node {
	int next,to;
} sxd[N<<1];
void add(int u,int v) {
	sxd[++cnt].next=head[u];
	sxd[cnt].to=v;
	head[u]=cnt;
}
struct ask {
	int a,b,d;
} q[N];
void dfs(int x,int f) {
	for(int i=1; (1<<i)<=depth[x]; i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x]; i; i=sxd[i].next) {
		if(sxd[i].to==f) continue;
		fa[sxd[i].to][0]=x;
		depth[sxd[i].to]=depth[x]+1;
		dfs(sxd[i].to,x);
	}
}
int lca(int x,int y) {
	if(depth[x]<depth[y]) swap(x,y);
	for(int i=20; i>=0; i--) if(depth[fa[x][i]]>=depth[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=20; i>=0; i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void upd(int &now,int to,int l,int r,int C) {
	if(!now) now=++tot;
	if(l==r) {
		tree[now]+=C;
		return;
	}
	int mid=(l+r)>>1;
	if(to<=mid) upd(ls[now],to,l,mid,C);
	else upd(rs[now],to,mid+1,r,C);
	tree[now]=max(tree[ls[now]],tree[rs[now]]);
}
int query(int &now,int l,int r) {
	if(!now || !tree[now]) return 0;
	if(l==r) return num[l];//é‡æ–°åç¦»æ•£åŒ–
	int mid=(l+r)>>1;
	if(tree[ls[now]]>=tree[rs[now]]) return query(ls[now],l,mid);
	else return query(rs[now],mid+1,r);
}
int merge(int &a,int b,int l,int r) {
	if(!a || !b) return a+b;
	if(l==r) {
		tree[a]+=tree[b];
		return a;
	}
	int mid=(l+r)>>1;
	ls[a]=merge(ls[a],ls[b],l,mid);
	rs[a]=merge(rs[a],rs[b],mid+1,r);
	tree[a]=max(tree[ls[a]],tree[rs[a]]);
	return a;
}
void dfs2(int x,int f) {
	for(int i=head[x]; i; i=sxd[i].next) {
		if(sxd[i].to==f) continue;
		dfs2(sxd[i].to,x);
		rt[x]=merge(rt[x],rt[sxd[i].to],1,num[0]);
	}
	ans[x]=query(rt[x],1,num[0]);
}
signed main() {
	n=read(),m=read();
	For(i,1,n-1) {
		x=read(),y=read(),add(x,y),add(y,x);
	}
	depth[1]=1;//ÎªÁË±ÜÃâÆæÆæ¹Ö¹ÖµÄ¹ø 
	dfs(1,0);
	For(i,1,m) {
		q[i].a=read(),q[i].b=read(),q[i].d=read();
		num[++num[0]]=q[i].d;
	}
	sort(num+1,num+num[0]+1);
	num[0]=unique(num+1,num+num[0]+1)-num-1;
	For(i,1,m) {
		q[i].d=lower_bound(num+1,num+num[0]+1,q[i].d)-num;
		int ll=lca(q[i].a,q[i].b);
		upd(rt[q[i].a],q[i].d,1,num[0],1);
		upd(rt[q[i].b],q[i].d,1,num[0],1);
		upd(rt[ll],q[i].d,1,num[0],-1);
		upd(rt[fa[ll][0]],q[i].d,1,num[0],-1);
	}
	dfs2(1,0);
	For(i,1,n) {
		write(ans[i]);
		puts("");
	}
	return 0;
}
