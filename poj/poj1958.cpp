#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int f3[120000],f4[120000],n=12;
signed main() {
	f3[1]=1;
	For(i,2,12) f3[i]=f3[i-1]*2+1;
	f4[1]=1;
	For(i,2,12) {
		f4[i]=f3[i];
		For(k,1,i-1) f4[i]=min(f4[i],f4[k]*2+f3[i-k]);	
	}
	For(i,1,12) cout<<f4[i]<<'\n';
	return 0;
}

