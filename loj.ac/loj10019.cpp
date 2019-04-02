/*
体积V=πR*R*H
侧面积A’=2*π*R*H
底面积A=π*R*R
*/
#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int mn[120],ans,n,m,h;
void dfs(int ceng,int r_now,int h,int s,int v_left) {
	if(s+2*v_left/r_now>ans) return;
	if(v_left-mn[m-ceng]<0) return;
	if(ceng==m) {
		if((!v_left) && s<ans) ans=s;
		return;
	}
	for(register int rr=r_now-1;rr>=m-ceng;rr--) for(register int hh=h-1;hh>=m-ceng;hh--) {
		int ss=s+2*rr*hh,vv=v_left-rr*rr*hh;
		dfs(ceng+1,rr,hh,ss,vv);
	}
}
signed main() {
	cin>>n>>m;
	ans=2147483647,h=1;
	For(i,1,m) {
		mn[i]=i*i*h;
		h++;
	}
	for(register int r=m;r*r*m<=n;r++) for(register int h=n/(r*r);h>=m;h--) {
		int s=r*r+2*r*h,v_left=n-r*r*h;
		dfs(1,r,h,s,v_left);
	}
	if(ans==2147483647) ans=0;
	cout<<ans;
	return 0;
}