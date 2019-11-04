#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
char ch[200005];
int n,ans;
signed main() {
	cin>>n;
	scanf("%s",ch+1);
	For(i,1,n) if((i&1) && ch[i]==ch[i+1]) ans++,ch[i+1]='a'+'b'-ch[i+1];
	cout<<ans<<'\n';
	printf("%s",ch+1);
	return 0;
}

