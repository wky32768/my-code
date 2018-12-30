#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
char a[1200000],b[1200000];
int kmp[1200000],len1,len2,k,ans;
signed main() {
	scanf("%s",a+1);
	scanf("%s",b+1);
	len1=strlen(a+1);
	len2=strlen(b+1);
	For(i,2,len2) {
		while(k && b[k+1]!=b[i]) k=kmp[k];
		if(b[k+1]==b[i]) k++;
		kmp[i]=k;
	}
	k=0;
	For(i,1,len1) {
		while(k && (k==len2 || b[k+1]!=a[i])) k=kmp[k];
		if(b[k+1]==a[i]) k++;
		if(k==len2) cout<<i-len2+1<<'\n';
	}
	For(i,1,len2) cout<<kmp[i]<<" ";
	return 0;
}

