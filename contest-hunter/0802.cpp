#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
deque <int> pai[15];
int x,ans,see[120],at=13,life;
int read() {
	char ch;
	cin>>ch;	
	if(ch-'0'>=2 && ch-'0'<=9) return ch-'0';
	else if(ch=='0') return 10;
	else if(ch=='A') return 1;
	else if(ch=='J') return 11;
	else if(ch=='Q') return 12;
	else if(ch=='K') return 13;
}
void make() {
	while(life<4) {
		int now=pai[at].back();		
		pai[at].pop_back();
		if(now!=13) {
			pai[now].push_front(now);
			see[now]++;
			at=now;	
		} else {
			life++;
			at=13;
		}
	}
}
signed main() {
	For(i,1,13) For(j,1,4) {
		x=read();
		pai[i].push_back(x);	
	}
	make();
	For(i,1,13) if(see[i]==4) ans++;
	cout<<ans;
	return 0;
}
