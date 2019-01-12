#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
priority_queue <int,vector <int>,greater <int> > q;
int n,x,ans;
signed main() {
	cin>>n;
	For(i,1,n) {
		cin>>x;
		q.push(x);	
	}
	while(q.size()!=1) {
		int a=q.top();
		q.pop();
		int b=q.top();	
		q.pop();
		ans+=(a+b);
		q.push(a+b);
	}
	cout<<ans;
}

