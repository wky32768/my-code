#include <bits/stdc++.h>
using namespace std;
long long n,m,opt,l,r,x,tree[4000002],a[4000002],add[4000002];
inline char gc() {
	static char sxd[1 << 14], *sss = sxd, *ttt = sxd;
	return (sss == ttt) && (ttt = (sss = sxd) + fread(sxd, 1, 1 << 14, stdin), sss == ttt) ? EOF : *sss++;
}
inline long long read() {
	char ch = gc();
	long long x = 0, f = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = gc();
	}
	while('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = gc();
	}
	return x * f;
}
inline void write(long long x) {
	if (x < 0)
		x = ~x + 1, putchar('-');
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
inline void build(const register int  rt,const register int l,const register int r) {
	if(l==r) {
		tree[rt]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
	return;
}
inline void pushdown(const register int rt,const register int l,const register int r) {
	if(add[rt]) {
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		tree[rt<<1]+=add[rt]*l;
		tree[rt<<1|1]+=add[rt]*r;
		add[rt]=0;
		return;
	}
	return;
}
inline void change(const register int L,const register int R,long long C,const register int l,const register int r,const register int rt) {
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
	return;
}
inline long long tot(const register int L,const register int R,const register int l,const register int r,const register int rt) {
	if(L<=l && r<=R) return tree[rt];
	int mid=(l+r)>>1;
	pushdown(rt,mid-l+1,r-mid);
	long long ans=0;
	if(L<=mid) ans+=tot(L,R,l,mid,rt<<1);
	if(R>mid) ans+=tot(L,R,mid+1,r,rt<<1|1);
	return ans;
}
signed main() {
	n = read(), m = read();
	for(register int i=1; i<=n; i++) a[i]=read();
	build(1,1,n);
	while(m--) {
		opt=read();
		if(opt==1) {
			l=read();
			r=read();
			x=read();
			change(l,r,x,1,n,1);
		} else {
			l=read();
			r=read();
			write(tot(l,r,1,n,1));
			puts("");
		}
	}
	return 0;
}
