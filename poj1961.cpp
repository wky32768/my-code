#include <bits/stdc++.h>
#define int long long
using namespace std;
char ch[1200000];
int n,k,kmp[1200000],t;
signed main() {
	while(cin>>n && n) {
		scanf("%s",ch+1);
		memset(kmp,0,sizeof kmp);
		k=0;
		for(int i=2;i<=n;i++) {
			while(k && ch[k+1]!=ch[i]) k=kmp[k];
			if(ch[k+1]==ch[i]) kmp[i]=++k;
			else kmp[i]=0;
		}
		printf("Test case #%lld\n",++t);
		for(int i=2;i<=n;i++) {
			if(i%(i-kmp[i])==0 && (i/(i-kmp[i])>1)) cout<<i<<" "<<(i/(i-kmp[i]))<<'\n';
		}
		puts("");
	}
	return 0;
}