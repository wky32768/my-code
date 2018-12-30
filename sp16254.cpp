#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
priority_queue <int> q1;
priority_queue <int,vector <int>,greater <int> > q2;
int t,cnt,tmp;
signed main() {
	cin>>t;
	while(t) {
		cin>>tmp;
		if(tmp==0) {
			while(!q1.empty()) q1.pop();
			while(!q2.empty()) q2.pop();
			cnt=0;
			t--;
		} else if(tmp==-1) {
			if(cnt & 1) {
				cout<<q2.top()<<'\n';
				q2.pop();
			} else {
				cout<<q1.top()<<'\n';	
				q1.pop();
			}
			cnt--;
		} else {
			int mid=q2.empty()?0:q2.top();	
			if(tmp>mid) q2.push(tmp);
			else q1.push(tmp);
			cnt++;
			if((cnt%2==1) && q1.size()>q2.size()) {
				int now=q1.top();
				q1.pop();		
				q2.push(now);
			} else if((cnt%2==0) && q2.size()>q1.size()) {
				int now=q2.top();
				q2.pop();	
				q1.push(now);
			}
		}
	}
	return 0;
}

