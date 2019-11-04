#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
struct node {int x,y;} d[5];
double a[5];
double dis(int x,int y) {
	return sqrt((d[x].x-d[y].x)*(d[x].x-d[y].x)+(d[x].y-d[y].y)*(d[x].y-d[y].y));	
}
bool ok() {
	memset(a,0,sizeof a);
	int cnt=0;
	For(i,1,4) For(j,i+1,4) {
		a[++cnt]=dis(i,j);
	}
	sort(a+1,a+7);
//	For(i,1,6) cout<<a[i]<<" ";
//	puts("");
	if(fabs(a[1]-a[4])<1e-8 && fabs(a[5]-a[6])<1e-8 && fabs(a[5]*a[5]/a[1]/a[1]-2)<1e-8) return 1;
	else return 0;
}
signed main() {
	For(i,1,4) d[i].x=read(),d[i].y=read();
	if(ok()) return puts("wen"),0;
	For(i,1,4) {
		d[i].x--;
		if(ok()) return puts("hai xing"),0;	
		d[i].x++;
		
		d[i].x++;
		if(ok()) return puts("hai xing"),0;	
		d[i].x--;
		
		d[i].y--;
		if(ok()) return puts("hai xing"),0;	
		d[i].y++;
		
		d[i].y++;
		if(ok()) return puts("hai xing"),0;	
		d[i].y--;
	}
	return puts("wo jue de bu xing"),0;
}

