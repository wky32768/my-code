#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
char a[1200000],b[1200000];
int s[1200000],f1[1200000],f2[1200000];
int get(int l,int r) {
	return f1[r]-f1[l-1]*s[r-l+1];
}
signed main() {
	s[0]=1;
	for(int i=1;i<=1000;i++) {
		s[i]=s[i-1]*13131;
	}
	while(scanf("%s",a+1)) {
		if(strlen(a+1)==1 && a[1]=='#') break;
		scanf("%s",b+1);
		int ans=0,n1=strlen(a+1),n2=strlen(b+1),sxd=1,akking=1,l=1;
		for(int i=1;i<=n1;i++) f1[i]=f1[i-1]*13131+a[i];
		for(int i=1;i<=n2;i++) f2[i]=f2[i-1]*13131+b[i];
		while(sxd==akking) {
			int r=l+n2-1;
			if(get(l,r)==f2[n2]) {
				ans++;
				l=r+1;
			} else l++;
			if(l-1+n2>n1) break;
		}	
		cout<<ans<<'\n';
	}
	return 0;
}