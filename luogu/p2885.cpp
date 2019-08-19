#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int Read() {
	int x=0,f=0; char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();	
	return f?-x:x;
}
int n,c,mx,mn,f[2][1200],h[100005],ans=0x3f3f3f3f;
signed main() {
	cin>>n>>c;
	For(i,1,n) {
		h[i]=Read();	
		mx=max(mx,h[i]);
	}
	memset(f,0x3f,sizeof f);
	int now=0;
	For(i,h[1],mx) f[now][i]=(i-h[1])*(i-h[1]);//最小值的初始值
	//n是10w,要滚存，落泪了 
	For(i,2,n) {
		now^=1;
		mn=0x3f3f3f3f;
		For(j,h[i-1],mx) {
			mn=min(mn,f[now^1][j]-c*j);
			if(j>=h[i]) f[now][j]=mn+(j-h[i])*(j-h[i])+c*j;//第一个式子 
		}
		mn=0x3f3f3f3f;
		for(int j=mx;j>=h[i];j--) {
			mn=min(mn,f[now^1][j]+c*j);
			f[now][j]=min(f[now][j],mn+(j-h[i])*(j-h[i])-c*j);//第二个式子 
		}
		For(j,0,mx) f[now^1][j]=0x3f3f3f3f;
	}
	For(i,1,mx) if(f[now][i]) ans=min(ans,f[now][i]);
	cout<<ans;
	return 0;
}
