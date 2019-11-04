#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
const int N=30000005;
int n,v[N],prime[N],ans,cnt;
signed main() {
	n=read();
	For(i,2,n) {
		if(v[i]==0) {
			v[i]=i;
			prime[++cnt]=i;
		}
		For(j,1,cnt) {
			if(prime[j]>v[i] || prime[j]>n/i) break;	
			v[i*prime[j]]=prime[j];
		}
	}
	For(i,1,n) ans+=v[i];
	cout<<ans;
	return 0;
}

