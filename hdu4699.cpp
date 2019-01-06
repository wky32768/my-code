#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,x,f[1200000],sum[1200000],cnt1,cnt2;
char s[3];
int a[1200000],b[1200000];
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
void write(int x) {
    if(x>=10) write(x/10);
    register char ch=x%10+'0';
    putchar(ch);
}
signed main() {
	while(scanf("%lld",&n)==1) {
		memset(sum,0,sizeof sum);
		memset(f,0,sizeof f);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		cnt1=cnt2=0;
		f[0]=-1000000000;
		while(n--){
			scanf("%s",s);
			if(s[0]=='I') {
				scanf("%lld",&x);
				a[++cnt1]=x;
				sum[cnt1]=sum[cnt1-1]+x;
				f[cnt1]=max(f[cnt1-1],sum[cnt1]);
			} else if(s[0]=='D') {
				if(cnt1!=0) cnt1--;
			} else if(s[0]=='L') {
				if(cnt1!=0) b[++cnt2]=a[cnt1--];
			} else if(s[0]=='R') {
				if(!cnt2) continue;
				a[++cnt1]=b[cnt2--];
				sum[cnt1]=sum[cnt1-1]+a[cnt1];
				f[cnt1]=max(f[cnt1-1],sum[cnt1]);
			} else if(s[0]=='Q') {
				scanf("%lld",&x);
				write(f[x]);
				puts("");
			}
		}
	}
	return 0;
}
