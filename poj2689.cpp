#include <bits/stdc++.h>
#define int long long
using namespace std;
bool v[12000000];
vector <int> p,ans;
signed main() {
	memset(v,1,sizeof v);
	for(i,2,65536) if(v[i]) {
		p.push_back(i);
		for(int j=2;j<=65536/i;j++) v[i*j]=0;
	}
	while(cin>>l>>r) {
		memset(v,1,sizeof v);
		ans.clear();
//		if(l==1) v[0]=0;	
		for(int i=0;i<p.size();i++) for(int j=(l-1)/p[i]+1;j<=r/p[i];j++) 
			if(j>1) v[p[i]*j-l]=0;
		for(int i=l;i<=r;i++) if(v[i-l]) ans.push_back(i);
		int mn=0x3f3f3f3f,mx=0,a1,a2,a3,a4;
		for(int i=0;i<=ans.size()-2;i++) {
			
			
		}
		
	}
	
}
