#include <bits/stdc++.h>
#define int long long
using namespace std;
unsigned long long f[1200000],p[1200000];
const int mod=131;
char ch[1200000];
int n,len;
signed main() {
	scanf("%s",ch+1);
	len=strlen(ch+1);
	cin>>n;
	p[0]=1;
	for(int i=1;i<=len;i++) {
		f[i]=f[i-1]*mod+ch[i]-'a'+1;	
		p[i]=p[i-1]*mod;
	}
	for(int i=1;i<=n;i++) {
		int q,w,e,r;
		cin>>q>>w>>e>>r;
		if(f[w]-f[q-1]*p[w-q+1]==f[r]-f[e-1]*p[r-e+1]) puts("Yes");
		else puts("No");	
	}
	return 0;
}
