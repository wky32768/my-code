#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}

const int N=1005;
int k,n,a[N],times[N];

signed main() {
	k=read();
	while(k--) {
		memset(a,0,sizeof a);
		memset(times,0,sizeof times);
		n=read();
		For(i,1,n) {
			a[i]=read();
			For(j,1,a[i]) times[j]++;
		}
		for(int i=n;i>=1;i--) if(times[i]>=i) {
			write(i); puts("");break;	
		}
	}
	return 0;
}

