#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,p,ans,a[120000],s[120000],w[120000];
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
inline void write(int x) {
    if(x>=10) write(x/10);
    register char ch=x%10+'0';
    putchar(ch);
}
signed main() {
	while(cin>>n && n) {
		memset(a,0,sizeof a);
		memset(s,0,sizeof s);
		memset(w,0,sizeof w);
		For(i,1,n) a[i]=read();
		a[n+1]=0;
		p=ans=0;
		For(i,1,n+1) {
			if(a[i]>s[p]) {
				s[++p]=a[i];
				w[p]=1;
			} else {
				int wid=0;
				while(s[p]>a[i]) {
					wid+=w[p];
					ans=max(ans,wid*s[p]);
					p--;
				}
				s[++p]=a[i];
				w[p]=wid+1;
			}
		}
		write(ans);
		puts("");
	}
}

