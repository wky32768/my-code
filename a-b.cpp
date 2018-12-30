#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
char aa[12000],bb[12000];
int a[12000],b[12000],c[12000],cnta,cntb,cntc,x;
bool bigger(char aa[],char bb[]) {
	if(strlen(aa+1)!=strlen(bb+1)) return strlen(aa+1)>strlen(bb+1);
	for(register int i=1;i<=strlen(aa+1);i++)
		if(aa[i]!=bb[i]) return aa[i]>bb[i];
	return 1;
}
signed main() {
	scanf("%s",aa+1);
	scanf("%s",bb+1);
	if(!bigger(aa,bb)) {
		putchar('-');
		swap(aa,bb);	
	}
	for(register int i=strlen(aa+1);i>=1;i--) a[++cnta]=aa[i]-'0';
	for(register int i=strlen(bb+1);i>=1;i--) b[++cntb]=bb[i]-'0';
	for(register int i=1;i<=max(strlen(aa+1),strlen(bb+1));i++) {
		c[i]=a[i]-b[i];
	}
	cntc=1;
	for(register int i=1;i<=max(strlen(aa+1),strlen(bb+1));i++) {
		if(c[i]<0){
			c[i]+=10;
			c[i+1]--;
		}
		if(c[i]>0)cntc=i;
	}
	for(int i=cntc;i>=1;i--) cout<<c[i];
	return 0;
}

