#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define lowbit(x) (x&(-x))
using namespace std;
int n,k,m,p,c[1200000];
char ch;
inline void change(int at,int x) {
	for(register int i=at;i<=n;i+=lowbit(i)) c[i]+=x;
}
inline int tot(int at) {
	int ans=0;
	for(register int i=at;i;i-=lowbit(i)) ans+=c[i];
	return ans;
}
signed main() {
	cin>>n>>k;
	For(i,1,k) {
		cin>>ch;
		if(ch=='A') {
			cin>>m;
			cout<<tot(m)<<'\n';
		} else if(ch=='B') {
			cin>>m>>p;
			change(m,p);
		} else {
			cin>>m>>p;	
			change(m,-p);
		}
	} 
	return 0;
}