#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=2500000;
int m,p,x,tree[N],add[N],a[N],cnt,ans;
void update(int which,int l,int r,int rt,int C) {
	if(l==r) {
		tree[rt]=C;
		return;
	}
	int mid=(l+r)>>1;
	if(which<=mid) update(which,l,mid,rt<<1,C);
	if(which>mid) update(which,mid+1,r,rt<<1|1,C);
	tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
	return;
}
int mx(int L,int R,int l,int r,int rt) {
	if(L<=l && r<=R) return tree[rt];
	int mid=(l+r)>>1,mxx=-0x3f3f3f3f;
	if(L<=mid) mxx=max(mxx,mx(L,R,l,mid,rt<<1));
	if(R>mid) mxx=max(mxx,mx(L,R,mid+1,r,rt<<1|1));
	return mxx;
}
char ch;
signed main() {
	cin>>m>>p;
	while(m--) {
		cin>>ch>>x;
		if(ch=='A') update(++cnt,1,200005,1,(x+ans)%p);
		else cout<<(ans=mx(cnt-x+1,cnt,1,200005,1))<<'\n';
	}
	return 0;
}