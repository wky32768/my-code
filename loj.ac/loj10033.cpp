#include <bits/stdc++.h>
using namespace std;
char a[1200000],b[1200000];
int k,n1,n2,ans,kmp[1200000];
signed main() {
	scanf("%s",a+1),scanf("%s",b+1);
	n1=strlen(a+1),n2=strlen(b+1);
	for(int i=2;i<=n2;i++) {
		while(k && b[k+1]!=b[i]) k=kmp[k];
		if(b[k+1]==b[i]) kmp[i]=++k;
		else kmp[i]=0;
	}
	k=0;
	for(int i=1;i<=n1;i++) {
		while(k && (k==n2 || b[k+1]!=a[i])) k=kmp[k];
		if(b[k+1]==a[i]) k++;	
		if(k==n2) ans++;
	}
	cout<<ans;
	return 0;
}