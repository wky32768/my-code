#include <bits/stdc++.h>
#define int long long
using namespace std;
string a[120000];
int t,n;
signed main() {
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++) {
			string str=a[i+1].substr(0,a[i].size());
			if(str==a[i]) {
				puts("NO");
				goto L1;
			}			
		}
		puts("YES");
		L1:;
	}
	return 0;
}