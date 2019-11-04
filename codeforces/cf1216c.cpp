#include <bits/stdc++.h>
#define For(i,a,b) for(register double i=a;i<=b;i+=0.5)
#define int long long
using namespace std;
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
double a[10],b[10];
int ok=1;
inline bool in(double x,double y) {
	if(x>=a[3] && x<=a[4] && y>=b[3] && y<=b[4]) return 1;	
	if(x>=a[5] && x<=a[6] && y>=b[5] && y<=b[6]) return 1;
	return 0;
}
signed main() {
	for(int i=1;i<=6;i++) cin>>a[i]>>b[i];
	For(i,b[1],b[2]) {
		if(!in(a[1],i)) {ok=0;break;}
		if(!in(a[2],i)) {ok=0;break;}
	}
	For(i,a[1],a[2]) {
		if(!in(i,b[1])) {ok=0;break;}
		if(!in(i,b[2])) {ok=0;break;}
	}
	if(!ok) puts("YES"); else puts("NO");
}

