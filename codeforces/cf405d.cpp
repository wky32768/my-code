//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int read() {
//	int x=0,f=0;
//	char ch=getchar();
//	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
//	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
//	return f?-x:x;
//}
//void write(int x) {
//	if(x<0) putchar('-'),x=-x;
//	if(x>=10) write(x/10);
//	putchar(x%10+'0');
//}
//const int N=1200000;
//int s,n,a[N],tot,ans[N],m;
//bool vis[N];
//signed main() {
//	freopen("sum.in","r",stdin);
//	freopen("sum.out","w",stdout);
//	s=read(),n=read();
//	for(int i=1; i<=n; i++) {
//		a[i]=read();
//		vis[a[i]]=1;
//		tot+=a[i]-1;
//	}
//	int old=tot;
//	for(int i=1; i<=s; i++) {
//		if(tot==0) break;
//		if(vis[i]) continue;
//		if(tot>=s-i) {
//			ans[++m]=i;
//			tot-=(s-i);
//		}
//	}
//	if(tot!=0) {
//		for(int i=1;i<=m;i++) {
//			if(!vis[ans[i]-tot] && ans[i]-tot>0) {
//				ans[i]-=tot;
//				break;
//			}
//		}
//	}
//	write(m);
//	puts("");
//	for(int i=1; i<=m; i++) {
//		write(ans[i]);
//		putchar(' ');
//	}
//	return 0;
//}
#include <bits/stdc++.h>
#define int long long
using namespace std;
int s,n,a[1200000],other;
bool vis[1200000];
int read() {
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
signed main() {
	s=1000000;
	cin>>n;
	for(register int i=1;i<=n;i++) {
		a[i]=read();
		vis[a[i]]=1;
	}
	cout<<n<<'\n';
	for(register int i=1;i<=s;i++) {
		if(vis[i]) {
			if(vis[s+1-i]) other++;
			else cout<<s+1-i<<" ";
		}
	}
	for(register int i=1;i<=s;i++) {
		if(!vis[i] && other && !vis[s+1-i]) {
			cout<<i<<" "<<s+1-i<<" ";
			other-=2;
		}
	}
	return 0;
}
