#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
char aa[2300],bb[2300];
int a[2300],b[2300],c[4600],cnta,cntb,cntc;
signed main() {
	scanf("%s",aa+1);
	scanf("%s",bb+1);
	for(register int i=strlen(aa+1); i>=1; i--) a[++cnta]=aa[i]-'0';
	for(register int i=strlen(bb+1); i>=1; i--) b[++cntb]=bb[i]-'0';
	for(register int i=1; i<=strlen(bb+1); i++) {
		for(register int j=1; j<=strlen(aa+1); j++) {
			c[i-1+j]+=a[j]*b[i];
		}
	}
//	cout<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]<<" "<<c[5]<<" "<<c[6]<<" "<<c[7]<<" "<<c[8]<<" "<<c[9]<<" "<<c[10]<<'\n';
	cntc=1;
	for(int i=1; i<=4500; i++) {
		if(c[i]>=10) {
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
		if(c[i]) cntc=i;
	}
	for(int i=cntc; i>=1; i--) cout<<c[i];
	return 0;
}

