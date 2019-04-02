#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m,tree1[1200000],tree2[1200000],opt,add1[1200000],add2[1200000];
void pushdown1(int rt,int l,int r) {
	if(add1[rt]) {
		add1[rt<<1]+=add1[rt];
		add1[rt<<1|1]+=add1[rt];
		tree1[rt<<1]+=add1[rt]*l;
		tree1[rt<<1|1]+=add1[rt]*r;
		add1[rt]=0;
	}
}
void pushdown2(int rt,int l,int r) {
	if(add2[rt]) {
		add2[rt<<1]+=add2[rt];
		add2[rt<<1|1]+=add2[rt];
		tree2[rt<<1]+=add2[rt]*l;
		tree2[rt<<1|1]+=add2[rt]*r;
		add2[rt]=0;
	}
}
void jia1(int L,int R,int l,int r,int rt) {
	if(L<=l && r<=R) {
		add1[rt]++;
		tree1[rt]++;
		return;
	}
	int mid=(l+r)>>1;
	pushdown1(rt,mid-l+1,r-mid);
	if(L<=mid) jia1(L,R,l,mid,rt<<1);
	if(R>mid) jia1(L,R,mid+1,r,rt<<1|1);
	tree1[rt]=tree1[rt<<1]+tree1[rt<<1|1];
}
void jia2(int L,int R,int l,int r,int rt) {
	if(L<=l && r<=R) {
		add2[rt]++;
		tree2[rt]++;
		return;
	}
	int mid=(l+r)>>1;
	pushdown2(rt,mid-l+1,r-mid);
	if(L<=mid) jia2(L,R,l,mid,rt<<1);
	if(R>mid) jia2(L,R,mid+1,r,rt<<1|1);
	tree2[rt]=tree2[rt<<1]+tree2[rt<<1|1];
}
int he1(int L,int R,int l,int r,int rt) {
	if(L<=l && r<=R) {
		return tree1[rt];
	}
	int mid=(l+r)>>1;
	pushdown1(rt,mid-l+1,r-mid);
	int zong=0;
	if(L<=mid) zong+=he1(L,R,l,mid,rt<<1);
	if(R>mid) zong+=he1(L,R,mid+1,r,rt<<1|1);
	return zong;
}
int he2(int L,int R,int l,int r,int rt) {
	if(L<=l && r<=R) {
		return tree2[rt];
	}
	int mid=(l+r)>>1;
	pushdown2(rt,mid-l+1,r-mid);
	int zong=0;
	if(L<=mid) zong+=he2(L,R,l,mid,rt<<1);
	if(R>mid) zong+=he2(L,R,mid+1,r,rt<<1|1);
	return zong;
}
signed main() {
	cin>>n>>m;
	For(i,1,m) {
		cin>>opt;
		if(opt==1) {
			int x,y;
			cin>>x>>y;
			jia1(x,x,1,n,1);
			jia2(y,y,1,n,1);	
		} else {
			int x,y;
			cin>>x>>y;	
			cout<<he1(1,y,1,n,1)-he2(1,x-1,1,n,1)<<'\n';
		}
	}
}

