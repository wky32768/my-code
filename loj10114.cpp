#include <bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
int c[1200000],n,cnt[1200000],x,y;
inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}
inline void change(int at) {
	for(register int i=at;i<=120000;i+=lowbit(i)) c[i]++;
}
inline int tot(int at) {
	int ans=0;
	for(register int i=at;i;i-=lowbit(i)) ans+=c[i];
	return ans;
}
signed main() {
	cin>>n;
	for(register int i=1;i<=n;i++) {
		x=read()+1;
		y=read();
		cnt[tot(x)]++;
		change(x);
	}
	for(int i=0;i<n;i++) {
		printf("%d",cnt[i]);
		puts("");
	}
 	return 0;
}
//由于x可能取0，而lowbit(0)=0，故add(0,1)会死循环。这就是为什么TLE的原因。所以将所有的 x++.
