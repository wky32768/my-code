#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define debug(x) cout<<"debug "<<(x)<<'\n';
#define int long long
using namespace std;

int n,k,prime[35]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127};
struct node {
	int w,p,times,limit;
	friend bool operator < (node a,node b) {return a.w<b.w;}
};
priority_queue <node> q;

signed main() {
	cin>>n>>k;
	k--;
	For(i,1,31) {
		int now=prime[i],t=0;
		for(;now<=n;now*=prime[i]) {t++; q.push((node) {now,prime[i],t,i-1}); }
	}
	while(k--) {
		node x=q.top(); q.pop();
		if(x.times>=2) For(i,1,x.limit) {
			q.push((node) {x.w/x.p*prime[i],x.p,x.times-1,i});
		}
	}
	return cout<<q.top().w,0;
}

