#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100002
using namespace std;
int p[N][21],head[N],tot,deep[N],tr[N*50],L[N*50],R[N*50],num[N],rt[N],top,ans[N],toy;
struct zzh {
	int n,to;
} e[N<<1];
struct bi {
	int a,b,d;
} q[N];
inline void add(int u,int v) {
	e[++tot].n=head[u];
	e[tot].to=v;
	head[u]=tot;
}
void dfs(int u,int fa) {
	for(int i=1; (1<<i)<=deep[u]; ++i)p[u][i]=p[p[u][i-1]][i-1];
	for(int i=head[u]; i; i=e[i].n)if(e[i].to!=fa) {
			int v=e[i].to;
			p[v][0]=u;
			deep[v]=deep[u]+1;
			dfs(v,u);
		}
}
inline int getlca(int a,int b) {
	if(deep[a]<deep[b])swap(a,b);
	for(int i=20; i>=0; --i)if(deep[a]-(1<<i)>=deep[b])a=p[a][i];
	if(a==b)return a;
	for(int i=20; i>=0; --i)if(p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return p[a][0];
}
void upd(int &cnt,int l,int r,int x,int y) {
	if(!cnt)cnt=++toy;
	if(l==r) {
		tr[cnt]+=y;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=x)upd(L[cnt],l,mid,x,y);
	else upd(R[cnt],mid+1,r,x,y);
	tr[cnt]=max(tr[L[cnt]],tr[R[cnt]]);
}
int query(int &cnt,int l,int r) {
	if(!tr[cnt]||!cnt)return 0;
	if(l==r)return num[l];
	int mid=(l+r)>>1;
	if(tr[L[cnt]]>=tr[R[cnt]])return query(L[cnt],l,mid);
	else return query(R[cnt],mid+1,r);
}
int merge(int &u,int v,int l,int r) {
	if(!u||!v)return u+v;
	if(l==r) {
		tr[u]+=tr[v];
		return u;
	}
	int mid=(l+r)>>1;
	L[u]=merge(L[u],L[v],l,mid);
	R[u]=merge(R[u],R[v],mid+1,r);
	tr[u]=max(tr[L[u]],tr[R[u]]);
	return u;
}
void dfs2(int u,int fa) {
	for(int i=head[u]; i; i=e[i].n)if(e[i].to!=fa) {
			int v=e[i].to;
			dfs2(v,u);
			rt[u]=merge(rt[u],rt[v],1,top);
		}
	ans[u]=query(rt[u],1,top);
}
int main() {
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1; i<n; ++i)scanf("%d%d",&u,&v),add(u,v),add(v,u);
	dfs(1,0);
	for(int i=1; i<=m; ++i)scanf("%d%d%d",&q[i].a,&q[i].b,&q[i].d),num[++top]=q[i].d;
	sort(num+1,num+top+1);
	top=unique(num+1,num+top+1)-num-1;
	for(int i=1; i<=m; ++i) {
		q[i].d=lower_bound(num+1,num+top+1,q[i].d)-num;
		int lca=getlca(q[i].a,q[i].b);
		upd(rt[q[i].a],1,top,q[i].d,1);
		upd(rt[q[i].b],1,top,q[i].d,1);
		upd(rt[lca],1,top,q[i].d,-1);
		upd(rt[p[lca][0]],1,top,q[i].d,-1);
	}
	dfs2(1,0);
	for(int i=1; i<=n; ++i)printf("%d\n",ans[i]);
	return 0;
}
