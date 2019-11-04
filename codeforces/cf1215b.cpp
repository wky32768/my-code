#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int n,a[200005];
int f1,f2,f3,f4;
signed main() {
	n=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) {
		f3+=f1,f4+=f2;
		if(a[i]>0) {
			f1++;
		} else {
			swap(f1,f2);
			f2++;
		}
	}
	cout<<f2+f4<<" "<<f1+f3<<'\n';
	return 0;
}
 
