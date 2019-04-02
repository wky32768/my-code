#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#define int unsigned long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
char ch[2400000];
int n,f[2400000],s[2400000],cnt,which,ans;
signed main() {
	cin>>n;
	scanf("%s",ch+1);
	if(n%2==0) return puts("NOT POSSIBLE"),0;
	s[0]=1;
	For(i,1,n) {
		f[i]=f[i-1]*131+ch[i];
		s[i]=s[i-1]*131;
	}
	For(i,1,n) {
		int a,b;
		if(i<=n/2) a=f[n/2+1]+(f[i-1]-f[i])*s[n/2-i+1];
		else a=f[n/2];
		if(i<=n/2+1) b=f[n]-f[n/2+1]*s[n/2];	
		else b=(f[i-1]-f[n/2]*s[i-n/2-1])*s[n-i]+f[n]-f[i]*s[n-i];
		if(a==b) {
			cnt++;
			if(cnt>1 && a!=ans) return puts("NOT UNIQUE"),0;
			which=i;
			ans=a;
		}
	}
	if(!cnt) return puts("NOT POSSIBLE"),0;
	if(which>n/2) {
		For(i,1,n/2) putchar(ch[i]);
	} else {
		For(i,1,n/2+1) if(i!=which) putchar(ch[i]);
	}
	return 0;
}