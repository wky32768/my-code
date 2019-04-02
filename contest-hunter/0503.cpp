#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int tree[560000],n,cnt1,cnt2;
void add(int x,int C) {
	for(int i=x; i<=n; i+=lowbit(i)) tree[i]+=C;
}
int sum(int x) {
	int ans=0;
	for(int i=x; i; i-=lowbit(i)) ans+=tree[i];
	return ans;
}
signed main() {
//	freopen("input.in","r",stdin);
//	freopen("0503.out","w",stdout);
	while(cin>>n) {
		n*=n;
		cnt1=cnt2=0;
		memset(tree,0,sizeof tree);
		int m;
		For(i,1,n){
			int x;
			cin>>x;
			if(!x) continue;
			cnt1+=m-sum(x-1)+1;
			add(x,1);
			m++;
		}
		memset(tree,0,sizeof tree);
		m=0;
		For(i,1,n){
			int x;
			cin>>x;
			if(!x) continue;
			cnt2+=m-sum(x-1)+1;	
			add(x,1);
			m++;
		}
		if(cnt1%2==cnt2%2) puts("TAK");
		else puts("NIE");
	}
	return 0;
}
