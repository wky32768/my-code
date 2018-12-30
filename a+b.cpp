#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
char aa[520],bb[520];
int a[520],b[520],c[520],cnta,cntb,x;
signed main() {
	scanf("%s",aa+1);
	scanf("%s",bb+1);
	for(register int i=strlen(aa+1);i>=1;i--) a[++cnta]=aa[i]-'0';
	for(register int i=strlen(bb+1);i>=1;i--) b[++cntb]=bb[i]-'0';
	for(int i=1;i<=max(strlen(aa+1),strlen(bb+1));i++) {
		int now=a[i]+b[i]+x;
		c[i]=now%10;	
		x=now/10;
	}
	int len=max(strlen(aa+1),strlen(bb+1));
	if(x) {
		c[++len]=x;
	}
	for(int i=len;i>=1;i--) cout<<c[i];
	return 0;
}

