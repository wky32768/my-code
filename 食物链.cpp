#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m,ans,fa[230000],rank[230000];
inline int read() {
	register int x=0,f=1;
	register char ch=getchar();
	while(!(ch>='0' && ch<='9')) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(int x) {
	if(x>=10) write(x/10);
	register char ch=x%10+'0';
	putchar(ch);
}
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void unity(int x,int y) {
	int xx=find(x),yy=find(y);
	if(rank[xx]<rank[yy]) fa[xx]=yy,rank[yy]=max(rank[yy],rank[xx]+1);
	else fa[yy]=xx,rank[xx]=max(rank[xx],rank[yy]+1);
}
signed main() {
	n=read(),m=read();
	For(i,1,n*3) fa[i]=i,rank[i]=1;
	For(i,1,m) {
		int opt=read(),x=read(),y=read();
		if(x>n || y>n) {
			ans++;
			continue;
		}
		if(opt&1) {
			if(find(x+n)==find(y) || find(x+2*n)==find(y)) {
				ans++;
				continue;
			}
			unity(x,y);
			unity(x+n,y+n);
			unity(x+n*2,y+n*2);      
		} else {
			if(find(x)==find(y) || find(x+2*n)==find(y)) {
				ans++;
				continue;
			}
			unity(x,y+n*2);
			unity(x+n,y);
			unity(x+n*2,y+n);
		}
	}
	cout<<ans;
	return 0;
}

