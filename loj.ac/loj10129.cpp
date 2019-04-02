#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {
	int v,mul,add;
}tree[1200000];
int n,m,p,opt,x,y,z,a[1200000];
void build(int rt,int l,int r) {
	tree[rt].mul=1;
	if(l==r) {
		tree[rt].v=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	tree[rt].v=(tree[rt<<1].v+tree[rt<<1|1].v)%p;
}
void pushdown(int rt,int l,int r) {
	tree[rt<<1].mul=(tree[rt<<1].mul*tree[rt].mul)%p;
	tree[rt<<1|1].mul=(tree[rt<<1|1].mul*tree[rt].mul)%p;
	tree[rt<<1].add=(tree[rt<<1].add*tree[rt].mul%p+tree[rt].add)%p;
	tree[rt<<1|1].add=(tree[rt<<1|1].add*tree[rt].mul%p+tree[rt].add)%p;
	tree[rt<<1].v=(tree[rt<<1].v*tree[rt].mul%p+tree[rt].add*l%p)%p;
	tree[rt<<1|1].v=(tree[rt<<1|1].v*tree[rt].mul%p+tree[rt].add*r%p)%p;
	tree[rt].mul=1;
	tree[rt].add=0;
	return;
}
void change1(int L,int R,int C,int l,int r,int rt) {
	if(L<=l && r<=R) {
		tree[rt].add=(tree[rt].add+C)%p;
		tree[rt].v=(tree[rt].v+C*(r-l+1)%p)%p;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(rt,mid-l+1,r-mid);
	if(L<=mid) change1(L,R,C,l,mid,rt<<1);
	if(R>mid) change1(L,R,C,mid+1,r,rt<<1|1);
	tree[rt].v=(tree[rt<<1].v+tree[rt<<1|1].v)%p;	
	return;
}
void change2(int L,int R,int C,int l,int r,int rt) {
	if(L<=l && r<=R) {
		tree[rt].mul=(tree[rt].mul*C)%p;
		tree[rt].add=(tree[rt].add*C)%p;
		tree[rt].v=(tree[rt].v*C)%p;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(rt,mid-l+1,r-mid);
	if(L<=mid) change2(L,R,C,l,mid,rt<<1);
	if(R>mid) change2(L,R,C,mid+1,r,rt<<1|1);
	tree[rt].v=(tree[rt<<1].v+tree[rt<<1|1].v)%p;
}
int tot(int L,int R,int l,int r,int rt) {
	if(L<=l && r<=R) return tree[rt].v;
	int mid=(l+r)>>1,ans=0;
	pushdown(rt,mid-l+1,r-mid);
	if(L<=mid) ans=(ans+tot(L,R,l,mid,rt<<1))%p;
	if(R>mid) ans=(ans+tot(L,R,mid+1,r,rt<<1|1))%p;
	return ans;
}
signed main() {
	cin>>n>>p;
	for(register int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	cin>>m;
	while(m--) {
		cin>>opt;
		if(opt==1) {
			cin>>x>>y>>z;
			change2(x,y,z,1,n,1);
		} else if(opt==2) {
			cin>>x>>y>>z;
			change1(x,y,z,1,n,1);
		} else if(opt==3){
			cin>>x>>y;
			cout<<tot(x,y,1,n,1)<<'\n';
		}
	}
	return 0;
}