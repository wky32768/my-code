#include <bits/stdc++.h>
#define int long long
using namespace std;
char ch[1200000];
int n,k,kmp[1200000];
signed main() {
	while(scanf("%s",ch+1)) {
		if(ch[1]=='.') break;
		memset(kmp,0,sizeof kmp);
		n=strlen(ch+1),k=0;
		for(int i=2;i<=n;i++) {
			while(k && ch[k+1]!=ch[i]) k=kmp[k];
			if(ch[k+1]==ch[i]) kmp[i]=++k;
			else kmp[i]=0;
		}
		if(n%(n-kmp[n])==0) cout<<(n/(n-kmp[n]))<<'\n';
		else cout<<"1\n";
	}
	return 0;
}