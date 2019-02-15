#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n;
string a,b;
map <string,bool> mp;
signed main() {
	cin>>n;
	while(n--) {
		cin>>a;
		getline(cin,b);
		if(a=="add") {
			mp[b]=1;
		} else {
			if(mp[b]==1) puts("yes");
			else puts("no");
		}
	}
	return 0;
}