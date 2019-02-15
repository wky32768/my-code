#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define lowbit(x) (x&(-x))
using namespace std;
int c[4100][4100],n,m,opt,x,y,a,b;
void change(int x,int y,int C) {
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=m;j+=lowbit(j))
			c[i][j]+=C;
}
int tot(int x,int y) {
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			ans+=c[i][j];
	return ans;
}
signed main() {
	cin>>n>>m;
	while(cin>>opt) {
		if(opt==1) {
			cin>>x>>y>>a;
			change(x,y,a);
		} else {
			cin>>x>>y>>a>>b;
			cout<<tot(a,b)-tot(a,y-1)-tot(x-1,b)+tot(x-1,y-1)<<'\n';
		}
	}
	return 0;
}
