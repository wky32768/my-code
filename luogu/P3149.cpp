/*
考虑每一步产生的影响
只有在被选中的区间内的数的逆序对会被改变
要离散化
只有递增的询问会使答案减少,所以最高就是把每一个数的逆序对数求出来
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define lowbit(x) (x&(-x))
using namespace std;
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
const int N=300005;
int n,m,tree[N<<2],ni[N],b[N],ans,cnt,x,now;
map <int,int> mp;
struct node {
	int w,id;
} a[N];
inline bool cmp1(node x,node y) {
	if(x.w!=y.w) return x.w<y.w;
	else return x.id<y.id;
}
inline bool cmp2(node x,node y) {
	return x.id<y.id;
}
inline void add(int x,int C) {
	for(register int i=x; i<=n; i+=lowbit(i)) tree[i]+=C;
}
inline int ask(int x) {
	int ans=0;
	for(register int i=x; i; i-=lowbit(i)) ans+=tree[i];
	return ans;
}
inline void li_san() {//离散化
	sort(a+1,a+n+1,cmp1);
	For(i,1,n) {
		if(a[i].w!=a[i-1].w) cnt++;
		mp[a[i].w]=cnt;
		b[a[i].id]=cnt;
	}
	sort(a+1,a+n+1,cmp2);
}
inline void solve() {
	for(register int i=n; i>=1; i--) {
		int now=ask(b[i]);
		ni[b[i]]+=now;
		add(b[i],1);
		ans+=now;
	}
	write(ans);
	puts("");
	For(i,1,m) {
		x=read();
		x=mp[a[x].w];
		if(x<=now) {
			write(ans);
			puts("");
			continue;
		}
		For(j,now+1,x) ans-=ni[j];
		now=x;
		write(ans);
		puts("");
	}
}
signed main() {
	n=read(),m=read();
	For(i,1,n) {
		a[i].w=read();
		a[i].id=i;
	}
	li_san();
	solve();
}
