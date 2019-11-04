#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
struct node {int x,id;} a[2005];
inline bool cmp(node a,node b) {return a.x>b.x;}
int n,ans[2005],tot;
signed main() {
	n=read();
	For(i,1,n) a[i]=(node) {read(),i};
	sort(a+1,a+n+1,cmp);
	For(i,1,n) {
		tot+=(i-1)*a[i].x+1;
		ans[i]=a[i].id;
	}
	cout<<tot<<'\n';
	For(i,1,n) {write(ans[i]); putchar(' ');}
	return 0;
}

