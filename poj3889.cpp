#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n;
double x,y,z;
inline int read() {
	register int x=0,f=1;
	register char ch=getchar();
	while(!(ch>='0' && ch<='9')) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=x*10ll+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int x) {
	if(x>=10ll) write(x/10ll);
	register char ch=x%10ll+'0';
	putchar(ch);
}
pair <int,int> calc(int n,int m) {
	if(n==0ll) return make_pair(0ll,0ll);
	int cnt=1ll<<(2ll*n-2ll),len=1ll<<(n-1ll);
	pair <int,int> s=calc(n-1ll,m%cnt);
	int x=s.first,y=s.second,which=m/cnt;
	if(which==0ll) return make_pair(y,x);
	if(which==1ll) return make_pair(x,y+len);
	if(which==2ll) return make_pair(x+len,y+len);
	if(which==3ll) return make_pair(len*2ll-y-1ll,len-x-1ll);
}
signed main() {
	cin>>n;
	while(n--) {
		int x,y,z;
		x=read(),y=read(),z=read();
		pair<int,int> a = calc(x, y - 1);
		pair<int,int> b = calc(x, z - 1);
		long long aa = a.first - b.first, bb = a.second - b.second;
		printf("%.0f",(double)sqrt(aa*aa+bb*bb)*10ll);
		puts("");
	}
}

