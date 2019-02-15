#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m,opt,x,y,tree[12000000],add[12000000];
void pushdown(int rt,int l,int r) {
	if(add[rt]) {
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		tree[rt<<1]+=add[rt]*l;
		tree[rt<<1|1]+=add[rt]*r;
		add[rt]=0ll;
	}
	return;
}
void change(int L,int R,int C,int l,int r,int rt) {
	if(L<=l && r<=R) {
		add[rt]++;
		tree[rt]+=(r-l+1);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(rt,mid-l+1,r-mid);
	if(L<=mid) change(L,R,C,l,mid,rt<<1);
	if(R>mid) change(L,R,C,mid+1,r,rt<<1|1);
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
	return;
}
int he(int L,int R,int l,int r,int rt) {
	if(L<=l && r<=R) {
		return tree[rt];
	}
	int mid=(l+r)>>1;
	pushdown(rt,mid-l+1,r-mid);
	int ans=0;
	if(L<=mid) ans+=he(L,R,l,mid,rt<<1);
	if(R>mid) ans+=he(L,R,mid+1,r,rt<<1|1);
	return ans;
}
signed main() {
	cin>>n>>m;
	while(m--) {
		cin>>opt;
		if(opt==1) {
			cin>>x>>y;
			change(x,y,1,1,n,1);
		} else {
			cin>>x;
			cout<<he(x,x,1,n,1)%2<<'\n';
		}
	}
	return 0;
}
