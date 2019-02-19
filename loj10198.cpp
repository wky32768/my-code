#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main() {
	cin>>n;
 	for(int i=2;i*i<=n;i++) if(n%i==0) n/=i;
 	cout<<n;
 	return 0;
}