#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
char ch[1200000];
int n,f[1200000],p[1200000];
signed main() {
	p[0]=1;
	for(int i=1;i<=400000;i++) p[i]=p[i-1]*131;
	while(scanf("%s",ch+1)==1) {
		int n=strlen(ch+1);
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++) f[i]=f[i-1]*131+(ch[i]-'a'+1);
		for(int i=1;i<=n;i++) {
			int s1=f[i],s2=f[n]-f[n-i]*p[i];
			if(s1==s2) cout<<i<<" ";
		}
		puts("");
	}
	return 0;
}