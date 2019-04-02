/*
分治解决最近点对
中间暴力判断
如果距离在Mn以外则一定比答案劣
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int N=230000;
int t,n,tmp[N],cnt;
struct point {double x,y;int at;} p[N];
double dis(point a,point b) {return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
bool cmp1(point a,point b) {return a.x<b.x;}
bool cmp2(int a,int b) {return p[a].y<p[b].y;}
double solve(int l,int r) {
	if(r-l==1) {
		if(p[l].at==p[r].at) return 1e10;
		else return dis(p[l],p[r]);
	} else if(r-l==2) {
		if(p[l].at==p[l+1].at) {
			if(p[l+1].at==p[l+2].at) return 1e10;
			else return min(dis(p[l],p[l+2]),dis(p[l+1],p[l+2]));
		} else {
			if(p[l].at==p[l+2].at) return min(dis(p[l],p[l+1]),dis(p[l+1],p[l+2]));
			else return min(dis(p[l],p[l+1]),dis(p[l],p[l+2]));
		}
	}
	int mid=(l+r)>>1;
	double mn=min(solve(l,mid),solve(mid+1,r));
	cnt=0;
	for(int i=l;i<=r;i++) if(p[i].x>=p[mid].x-mn && p[i].x<=p[mid].x+mn) tmp[++cnt]=i;
	sort(tmp+1,tmp+cnt+1,cmp2);
	for(int i=1;i<=cnt;i++) for(int j=i+1;j<=cnt;j++) if(p[tmp[i]].at!=p[tmp[j]].at) {
		if(p[tmp[j]].y-p[tmp[i]].y>=mn) break;//重要剪枝，后面的一定不会更新答案
		else mn=min(mn,dis(p[tmp[i]],p[tmp[j]]));
	}
	return mn;
}
signed main() {
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y),p[i].at=1;
		for(int i=1+n;i<=n*2;i++) scanf("%lf%lf",&p[i].x,&p[i].y),p[i].at=2;
		sort(p+1,p+n*2+1,cmp1);
		printf("%.3lf\n",solve(1,n*2));
	}
	return 0;
}