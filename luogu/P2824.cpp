#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;

inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}

const int N=400005;
int n,m,q,a[N],tree[N<<2],add[N<<2];
struct node {int opt,l,r;} sxd[N];

inline void build(int l,int r,int rt,int x) {
	if(l==r) {tree[rt]=(a[l]>=x);return;}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1,x),build(mid+1,r,rt<<1|1,x);
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}

inline void pushdown(int rt,int l,int r) {
	if(!add[rt]) return;
	add[rt<<1]=add[rt];
	add[rt<<1|1]=add[rt];
	tree[rt<<1]=l*(add[rt]-1);
	tree[rt<<1|1]=r*(add[rt]-1);
	add[rt]=0;
}

inline void change(int L,int R,int C,int l,int r,int rt) {
	if(L>R) return;
	if(L<=l && r<=R) {
		add[rt]=C+1;
		tree[rt]=(r-l+1)*C;
		return;	
	}
	int mid=(l+r)>>1;
	pushdown(rt,mid-l+1,r-mid);
	if(L<=mid) change(L,R,C,l,mid,rt<<1);
	if(R>mid) change(L,R,C,mid+1,r,rt<<1|1);
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}

inline int ask(int L,int R,int l,int r,int rt) {
	if(L>R) return 0;
	if(L<=l && r<=R) return tree[rt];
	int mid=(l+r)>>1,tot=0;
	pushdown(rt,mid-l+1,r-mid);
	if(L<=mid) tot+=ask(L,R,l,mid,rt<<1);
	if(R>mid) tot+=ask(L,R,mid+1,r,rt<<1|1);
	return tot;
}

inline bool ok(int x) {
	memset(tree,0,sizeof tree);
	build(1,n,1,x);
	memset(add,0,sizeof add);
	For(i,1,m) {
		int zong=ask(sxd[i].l,sxd[i].r,1,n,1);
		if(sxd[i].opt==0) {
			change(sxd[i].r-zong+1,sxd[i].r,1,1,n,1);
			change(sxd[i].l,sxd[i].r-zong,0,1,n,1);
		} else {
			change(sxd[i].l,sxd[i].l+zong-1,1,1,n,1);
			change(sxd[i].l+zong,sxd[i].r,0,1,n,1);
		}
	}
	return ask(q,q,1,n,1);
}

signed main() {
	n=read(),m=read();
	For(i,1,n) a[i]=read();
	For(i,1,m) sxd[i]=(node) {read(),read(),read()};
	q=read();
	int l=1,r=n,ans=0;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(ok(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return cout<<ans,0;	
}

