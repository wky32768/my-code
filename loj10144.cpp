//treap实现平衡树
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1200000;
struct treap {
	int l,r,val,dat,cnt,siz;//val数值，dat随机权值，cnt几个相同的数，siz子树大小
} a[N];
int n,root,tot,opt,ans,x,now;
int make(int val) {
	a[++tot].val=val;
	a[tot].dat=rand();
	a[tot].cnt=a[tot].siz=1;
	return tot;
}
void upd(int rt) {
	a[rt].siz=a[a[rt].l].siz+a[a[rt].r].siz+a[rt].cnt;
}
void build() {
	make(-0x3f3f3f3f);
	make(0x3f3f3f3f);
	root=1;
	a[1].r=2;
	upd(root);
}
int search_rank(int at,int x) {
	if(!at) return 0;
	if(a[at].val==x) return a[a[at].l].siz+1;
	if(a[at].val>x) return search_rank(a[at].l,x);
	return search_rank(a[at].r,x)+a[a[at].l].siz+a[at].cnt;
}
int search_val(int at,int x) {
	if(!at) return 0x3f3f3f3f;
	if(a[a[at].l].siz>=x) return search_val(a[at].l,x);
	if(a[a[at].l].siz+a[at].cnt>=x) return a[at].val;
	return search_val(a[at].r,x-a[a[at].l].siz-a[at].cnt);
}
void right_xuan(int &p) {
	int q=a[p].l;
	a[p].l=a[q].r;
	a[q].r=p;
	p=q;
	upd(a[p].r);
	upd(p);
}
void left_xuan(int &p) {
	int q=a[p].r;
	a[p].r=a[q].l;
	a[q].l=p;
	p=q;
	upd(a[p].l);
	upd(p);
}
void insert(int &at,int val) {
	if(!at) {
		at=make(val);
		return;
	}
	if(a[at].val==val) {
		a[at].cnt++;
		upd(at);
		return;
	}
	if(a[at].val>val) {
		insert(a[at].l,val);
		if(a[a[at].l].dat>a[at].dat) right_xuan(at);
	}
	if(a[at].val<val) {
		insert(a[at].r,val);
		if(a[a[at].r].dat>a[at].dat) left_xuan(at);
	}
	upd(at);
}
int pre(int val) {
	int ans=1,at=root;
	while(at) {
		if(a[at].val==val) {
			if(a[at].l) {
				at=a[at].l;
				while(a[at].r) at=a[at].r;
				ans=at;
			}
			break;
		}
		if(a[at].val<val && a[at].val>a[ans].val) ans=at;
		at=a[at].val>val?a[at].l:a[at].r;
	}
	return a[ans].val;
}
int nxt(int val) {
	int ans=2,at=root;
	while(at) {
		if(a[at].val==val) {
			if(a[at].r) {
				at=a[at].r;
				while(a[at].l) at=a[at].l;
				ans=at;
			}
			break;
		}
		if(a[at].val>val && a[at].val<a[ans].val) ans=at;
		at=a[at].val>val?a[at].l:a[at].r;
	}
	return a[ans].val;
}
void del(int &at,int val) {
	if(!at) return;
	if(a[at].val==val) {
		if(a[at].cnt>1) {
			a[at].cnt--;
			upd(at);
			return;
		}
		if(a[at].l || a[at].r) {
			if(a[at].r==0 || a[a[at].l].dat>a[a[at].r].dat) right_xuan(at),del(a[at].r,val);
			else left_xuan(at),del(a[at].l,val);
			upd(at);
		} else at=0;
		return;
	}
	a[at].val>val?del(a[at].l,val):del(a[at].r,val);
	upd(at);
}
map <int,bool> mp;
signed main() {
	build();
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++) {
		cin>>opt>>x;
		if(sum==0) {
			now=opt;
			insert(root,x);
			sum++;
		} else if(opt==now) {
			insert(root,x);
			sum++;
		} else {
			int aa=pre(x),bb=nxt(x),cc=0x3f3f3f3f,which=0;
			if(x-aa>=0) if(x-aa<cc) {
				cc=x-aa,which=1;
			}
			if(bb-x<120000000) if(bb-x<cc) {
				cc=bb-x,which=2;
			}
			if(cc==0x3f3f3f3f) continue;
			ans+=cc;
			sum--;	
			if(which==1) del(root,aa);
			else if(which==2) del(root,bb);
			ans%=1000000;
		}
	}
	cout<<ans;	
	return 0;
}