#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
#define il inline
#define L (x<<1)
#define R (x<<1|1)
using namespace std;
il int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
il void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}

const int N=800005;
int n,m,opt,l0,r0,l1,r1,add[N];
struct node {int l,r,ans,ml,mr,tot;} t[N];

il void upd(int x) {
	t[x].tot=t[L].tot+t[R].tot;
	t[x].ml=(t[L].r-t[L].l+1==t[L].ml)?(t[L].r-t[L].l+1+t[R].ml):(t[L].ml);
	t[x].mr=(t[R].r-t[R].l+1==t[R].mr)?(t[R].r-t[R].l+1+t[L].mr):(t[R].mr);
	t[x].ans=max(max(t[L].ans,t[R].ans),t[L].mr+t[R].ml);
}

il void build(int l,int r,int rt) {
	if(l==r) {t[rt]=(node) {l,r,0,0,0,1};return;}
	t[rt].l=l,t[rt].r=r;
	int mid=(l+r)>>1;
	build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
	upd(rt);
}

il void pd(int x) {
	if(!add[x]) return;
	if(add[x]==2) {
		t[L].tot=t[L].r-t[L].l+1;
		t[R].tot=t[R].r-t[R].l+1;
		t[L].ans=t[R].ans=t[L].ml=t[L].mr=t[R].ml=t[R].mr=0;
		add[L]=add[R]=2;
	} else {
		t[L].tot=t[R].tot=0;
		t[L].ml=t[L].mr=t[L].r-t[L].l+1;
		t[R].ml=t[R].mr=t[R].r-t[R].l+1;
		add[L]=add[R]=1;
	}
	add[x]=0;
}

il void change(int l,int r,int C,int rt) {
	if(l<=t[rt].l && t[rt].r<=r) {
		t[rt].tot=C*(t[rt].r-t[rt].l+1);
		add[rt]=C+1;
		if(C) t[rt].ans=t[rt].ml=t[rt].mr=0;
		else t[rt].ans=t[rt].ml=t[rt].mr=t[rt].r-t[rt].l+1;
		return;
	}
	pd(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid) change(l,r,C,rt<<1);
	if(r>mid) change(l,r,C,rt<<1|1);
	upd(rt);
}

il int ask(int l,int r,int rt) {
	if(l<=t[rt].l && t[rt].r<=r) return t[rt].tot;
	pd(rt);
	int mid=(t[rt].l+t[rt].r)>>1,sum=0;	
	if(l<=mid) sum+=ask(l,r,rt<<1);
	if(r>mid) sum+=ask(l,r,rt<<1|1);
	return sum;
}

il node query(int l,int r,int rt) {
	if(l<=t[rt].l && t[rt].r<=r) return t[rt];
	pd(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(r<=mid) return query(l,r,rt<<1);
	else if(l>mid) return query(l,r,rt<<1|1);
	node ll=query(l,r,rt<<1),rr=query(l,r,rt<<1|1),res;
	res.tot=ll.tot+rr.tot;
	res.ml=(ll.r-ll.l+1==ll.ml)?ll.r-ll.l+1+rr.ml:ll.ml;
	res.mr=(rr.r-rr.l+1==rr.mr)?rr.r-rr.l+1+ll.mr:rr.mr;
	res.ans=max(max(ll.ans,rr.ans),ll.mr+rr.ml);
	return res;
}


signed main() {
	n=read(),m=read();
	build(1,n,1);
	For(i,1,m) {
		opt=read();
		if(opt==0) {
			l0=read(),r0=read();
			change(l0,r0,0,1);
		} else if(opt==1) {
			l0=read(),r0=read(),l1=read(),r1=read();
			int sum=ask(l0,r0,1);
			if(!sum) continue;
			change(l0,r0,0,1);
			int l=1,r=r1-l1+1,ans=0;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(mid-ask(l1,l1+mid-1,1)<=sum) ans=mid,l=mid+1;
				else r=mid-1;	
			}
			change(l1,l1+ans-1,1,1);
		} else if(opt==2) {
			l0=read(),r0=read();
			write(query(l0,r0,1).ans); puts("");
		}
	}
	return 0;
}

