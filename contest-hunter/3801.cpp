#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=100005;
int n,a[N],last[2],zero,one,b[N];//one:µÚ1,3,5¶Î  zero£ºµÚ2,4,6¶Î 
double ans_xor,ans_and,ans_or;
inline int read() {
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline void write(int x) {
	if(x<0) putchar('-'),x=-x;	
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
signed main() {
	n=read();
	For(i,1,n) a[i]=read();
	For(at,0,31) {
		last[0]=last[1]=zero=one=0;
		double temp=(double)(1<<at)/n/n;
		For(i,1,n) {
			b[i]=((a[i]>>at)&1);
			if(b[i]==1) {
				ans_xor+=temp;
				ans_and+=temp;
				ans_or+=temp;	
							
				ans_or+=(double)(1<<at)*(i-1)*2.0/n/n;
				ans_and+=(double)(1<<at)*(i-last[0]-1)*2.0/n/n;
				ans_xor+=(double)(1<<at)*one*2.0/n/n;
			} else {
				ans_or+=(double)(1<<at)*(last[1])*2.0/n/n;
				ans_xor+=(double)(1<<at)*zero*2.0/n/n;
			}
			one++;
			if(b[i]==1) swap(one,zero);
			last[b[i]]=i;
		}
	}
	printf("%.3f %.3f %.3f",ans_xor,ans_and,ans_or);
	return 0;
}
