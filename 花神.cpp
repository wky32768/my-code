#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define lowbit(x) (x & (-x))
using namespace std;
int fa[120000],tree[1200000],n,m,a[120000];
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}	
void add(int x,int c) {
	for(;x<=n;x+=lowbit(x)) tree[x]+=c;
}
int he(int x) {
	int ans=0;
	for(;x;x-=lowbit(x)) ans+=tree[x];
	return ans;
}
signed main() {
	cin>>n;
	For(i,1,n) {
		cin>>a[i];	
		add(i,a[i]);
		if(a[i]>1) fa[i]=i;
		else fa[i]=i+1;
	}
	fa[n+1]=n+1;
	cin>>m;
	while(m--) {
		int opt,l,r;
		cin>>opt>>l>>r;
		if(l>r) swap(l,r);
		if(opt==1) {
			cout<<he(r)-he(l-1)<<'\n';	
		} else {
			for(int i=find(l);i<=r;i=find(i+1)) {
				int turn=sqrt(a[i]);
				add(i,turn-a[i]);
				a[i]=turn;
				if(a[i]<=1) fa[i]=fa[i+1];
			}
		}	
	}
	return 0;
}

