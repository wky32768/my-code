#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,m,x,y;
int a[520000],st[520000][20];
int read() {
	int f=0;
	char ch=getchar();
	while(!(ch>='0' && ch<='9')) ch=getchar();
	while(ch>='0' && ch<='9') {
		f=f*10+ch-'0';
		ch=getchar();
	}
	return f;
}
void pre() {
	for(int i=1;(1<<i)<=n;i++) 
		for(int l=1;l+(1<<i)-1<=n;l++) {
			st[l][i]=max(st[l][i-1],st[l+(1<<(i-1))][i-1]);
		}
}
int count(int l,int r) {
	int length=log2(r-l+1);
	return max(st[l][length],st[r-(1<<length)+1][length]);
}
signed main() {
	cin>>n>>m;
	For(i,1,n) {
		a[i]=read();
		st[i][0]=a[i];
	}
	pre();
	while(m--) {
		x=read();
		y=read();
		if(x>y) swap(x,y);
		cout<<count(x,y)<<'\n';
	}
	return 0;
}