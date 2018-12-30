#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int t,s,x;
map <int,int> mp;
queue <int> q;
int change(int x,int i) {
	x^=(1<<i);
	if((i%5)<4) x^=(1<<(i+1));
	if((i%5)>0) x^=(1<<(i-1));
	if(i>=5) x^=(1<<(i-5));
	if(i<=19) x^=(1<<(i+5));
	return x;
}
void bfs() {
	int x=(1<<25)-1;
	mp[x]=1;
	q.push(x);
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		if(mp[now]>6) break;
		For(i,0,24) {
			int to=change(now,i);	
			if(mp[to]) continue;
			mp[to]=mp[now]+1;
			q.push(to);
		}
	}
}
signed main() {
	cin>>t;
	bfs();
	while(t--) {
		s=0;
		For(i,0,24) scanf("%1d",&x),s+=(1<<i)*x;
		cout<<mp[s]-1;
		puts("");
	}
	return 0;
}

