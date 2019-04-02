#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,r,s[5200][5200],ans;
inline int read() {
    register int x=0,f=1;
    register char ch=getchar();
    while(!(ch>='0' && ch<='9')) {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
signed main() {
	int mxa=0,mxb=0;
	cin>>n>>r;
	while(n--) {
		int x=read(),y=read(),z=read();
		mxa=max(mxa,x+1);
		mxb=max(mxb,y+1);
		s[x+1][y+1]+=z;	
	}
	mxa=max(mxa,r);
	mxb=max(mxb,r);
	For(i,1,5001) For(j,1,5001) s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	For(i,r,5001) For(j,r,5001) ans=max(ans,s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r]);
	cout<<ans;
	return 0;
}

