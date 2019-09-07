#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int n;
signed main() {
	cin>>n;
	if(n==1) return cout<<"YES\n1 2",0;
	if(n%2==0) return puts("NO"),0;
	puts("YES");
	For(i,1,n) if(i%2==1) cout<<(i-1)*2+1<<" ";else cout<<i*2<<" ";
	For(i,1,n) if(i%2==0) cout<<(i-1)*2+1<<" ";else cout<<i*2<<" ";
	return 0;
}

