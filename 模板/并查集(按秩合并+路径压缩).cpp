#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
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
int n,m,fa[120000],rank[120000];
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
signed main() {
	n=read(),m=read();
	For(i,1,n) fa[i]=i,rank[i]=1;
	while(m--) {
		int opt=read(),x=read(),y=read();
		if(opt&1) {
			int xx=find(x),yy=find(y);
			if(rank[xx]<rank[yy]) fa[xx]=yy,rank[yy]=max(rank[yy],rank[xx]+1);
			else fa[yy]=xx,rank[xx]=max(rank[xx],rank[yy]+1);
		} else {
			int xx=find(x),yy=find(y);
			if(xx==yy) puts("Y");
			else puts("N");	
		}
	}
	return 0;
}

