#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,a[105],ans;
bool vis[105];
inline bool tot() {For(i,1,n) if(!vis[i]) return 1;return 0;}
signed main() {
	cin>>n; For(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	while(tot()!=0) {
		int now=0;
		For(i,1,n) if(!vis[i]) {now=i;break;}
		ans++;
		For(i,1,n) if(a[i]%a[now]==0) vis[i]=1;		
	}
	cout<<ans;
	return 0;
}

