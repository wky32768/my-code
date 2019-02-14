#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define next(a,b) b==9?dfs(a+1,1):dfs(a,b+1)
using namespace std;
int score,ans=-1,x,b[12][12],r[12][12],l[12][12],g[12][12];
inline int get(const register int x,const register int y,const register int k) {
	if(x==5 && y==5) return 10*k;
	else if(x>=4 && x<=6 && y>=4 && y<=6) return 9*k;
	else if(x>=3 && x<=7 && y>=3 && y<=7) return 8*k;
	else if(x>=2 && x<=8 && y>=2 && y<=8) return 7*k; 
	else return 6*k;
}
inline bool ok(const register int x,const register int y,const register int k) {
	if(r[x][k] || l[y][k] || g[(x-1)/3*3+(y-1)/3+1][k]) return 0;
	b[x][y]=k;
	r[x][k]=l[y][k]=g[(x-1)/3*3+(y-1)/3+1][k]=1;
	score+=get(x,y,k);
	return 1;
}
inline void del(const register int x,const register int y,const register int k) {
	b[x][y]=0;
	r[x][k]=l[y][k]=g[(x-1)/3*3+(y-1)/3+1][k]=0;
}
inline void dfs(const register int x,const register int y) {
	if(x==10 && y==1) {
		ans=max(ans,score);
		return;
	}
	if(b[x][y]) {
		next(x,y);
		return;
	}
	For(i,1,9) {
		register int old=score;
		if(ok(x,y,i)) {
			next(x,y);
			del(x,y,i);
			score=old;
		}
	}
	return;
}
signed main() {
	for(register int i=9;i>=1;i--) For(j,1,9) {
		cin>>x;
		if(x) ok(i,j,x);
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}