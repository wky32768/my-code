#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int a,b,c;
int ksm(int a,int b,int c) {
	int ans=0;
	while(b) {
		if(b&1) ans=(ans+a)%c;
		b>>=1;
		a=(a*2)%c;
	}		
	return ans;
}
signed main() {
	cin>>a>>b>>c;
	if(c==1) cout<<"0";
	else cout<<ksm(a,b,c);
}

