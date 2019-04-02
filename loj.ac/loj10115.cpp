#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m,c1[120000],c2[120000],opt,x,y;
void change1(int at,int x) {
	for(int i=at;i<=n;i+=lowbit(i)) c1[i]+=x;
}
void change2(int at,int x) {
	for(int i=at;i<=n;i+=lowbit(i)) c2[i]+=x;
}
int tot1(int at) {
	int ans=0;
	for(int i=at;i;i-=lowbit(i)) ans+=c1[i];
	return ans;
}
int tot2(int at) {
	int ans=0;
	for(int i=at;i;i-=lowbit(i)) ans+=c2[i];
	return ans;
}
signed main() {
	cin>>n>>m;
	while(m--) {
		cin>>opt>>x>>y;
		if(opt==1) {
			change1(x,1);
			change2(y,1);
		} else {
			cout<<tot1(y)-tot2(x-1);
			puts("");
		}
	}
	return 0;
}