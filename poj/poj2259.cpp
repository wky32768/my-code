#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
deque <int> q[1200],p;
int n,m,zu[1200000],t,x;
string ch;
signed main() {
	while(cin>>n && n) {
		t++;
		printf("Scenario #%lld\n",t);
		p.clear();
		memset(zu,0,sizeof zu);
		for(int i=1;i<=n;i++) q[i].clear();
		for(int i=1;i<=n;i++) {
			cin>>m;
			for(int j=1;j<=m;j++) {
				cin>>x;
				zu[x]=i;
			}
		}
		while(cin>>ch) {
			if(ch=="STOP") break;
			if(ch[0]=='E') {
				cin>>x;
				if(!q[zu[x]].size())  p.push_back(zu[x]);
				q[zu[x]].push_back(x);
			} else {
				int z=p.front();
				cout<<q[z].front()<<'\n';
				q[z].pop_front();
				if(!q[z].size()) p.pop_front();
			}
		}
		puts("");
	}
	return 0;

}