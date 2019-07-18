#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
vector <int> q[N];
int fa[N][22],n,m,s,x,y,depth[N];
#define pc putchar
inline char gc() {
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read() {
	register int x = 0, f = 0;
	register char ch = gc();
	while (!isdigit(ch)) {
		f |= (ch == '-');
		ch = gc();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = gc();
	}
	return f ? -x : x;
}
inline void write(register int x) {
	if (x < 0) {
		pc('-');
		x = -x;
	}
	if (x >= 10)
		write(x / 10);
	pc(x % 10 + '0');
}
inline void dfs(int x,int f) {
    fa[x][0]=f;
    depth[x]=depth[f]+1;
    for(int i=1;i<=20;i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=0;i<(int)q[x].size();i++) {
        if(q[x][i]==f) continue;
        dfs(q[x][i],x);
    }
}
inline int lca(int x,int y) {
    if(depth[x]>depth[y]) swap(x,y);
    for(register int i=20;i>=0;i--) {
        if(depth[x]<=depth[y]-(1<<i)) y=fa[y][i];
    }
    if(x==y) return x;
    for(register int i=20;i>=0;i--) {
        if(fa[x][i]!=fa[y][i] && fa[x][i] && fa[y][i]) {
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}
signed main() {
    cin>>n>>m>>s;
    for(register int i=1;i<n;i++) {
        x=read(),y=read();
        q[x].push_back(y);
        q[y].push_back(x);
    }
    dfs(s,0);
    for(register int i=1;i<=m;i++) {
        x=read(),y=read();
        write(lca(x,y));
        puts("");
    }
    return 0;
}