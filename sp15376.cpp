#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
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
int n,mid,tmp,cnt,a[120000];
bool vis[120000];
signed main() {
//	freopen("ak.in","r",stdin);
	while(scanf("%lld",&tmp) && tmp) {
		n=cnt=mid=1;
		a[n]=tmp;
		memset(vis,0,sizeof vis);
		while(tmp=read()) {
			if(tmp==0) break;
			if(tmp==-1) {
				write(a[mid]);
				puts("");
				vis[mid]=1;
				cnt--;
				if(cnt&1) {
L1:
					;
					mid++;
					if(vis[mid]) goto L1;
				} else {
L2:
					;
					mid--;
					if(vis[mid]) goto L2;
				}
			} else {
				a[++n]=tmp;
				cnt++;
				if(cnt&1) {
L3:
					;
					mid++;
					if(vis[mid]) goto L3;
				}
			}
		}
		puts("");
	}
	return 0;
}

