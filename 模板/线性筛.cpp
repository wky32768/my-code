#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m,prime[12000000],v[12000000],cnt,x;
signed main() {
	cin>>n>>m;
	For(i,2,n) {
		if(v[i]==0) {
			v[i]=i;
			prime[++cnt]=i;
		}
		For(j,1,cnt) {
			if(prime[j]>v[i] || prime[j]>n/i) break;	
			v[i*prime[j]]=prime[j];
		}
	}
	while(m--) {
		cin>>x;
		if(v[x]==x) puts("Yes");
		else puts("No");
	}
	return 0;
}

