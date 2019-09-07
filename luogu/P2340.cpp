#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=405;
const int B=500000;
int n,cnt,f[2000001],ans,x,y;//f[i]://智商综合为I是情商的最大值 
int a[N],b[N];
signed main() {
	n=read();
	For(i,1,n) {
		x=read(),y=read();
		if(x>0 || y>0) a[++cnt]=x,b[cnt]=y;
	}
	memset(f,0xcf,sizeof f);
	f[B]=0;
	For(j,1,cnt) {
		if(a[j]>=0) {
			for(int i=B+B;i>=a[j];i--)
				f[i]=max(f[i],f[i-a[j]]+b[j]);
		} else {
			for(int i=0;i<=B+B+a[j];i++)
				f[i]=max(f[i],f[i-a[j]]+b[j]);	
		}
		//注意正负的更新顺序是不一样的 
	}
	For(i,B,B+B) if(f[i]>=0) {ans=max(ans,f[i]-B+i);}
	cout<<ans;
	return 0;
}

