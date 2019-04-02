#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cctype>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int mod=99991;
int n,tot,snow[120000][10],head[120000],nxt[120000],a[120];//snow里动态开点存储，通过链表查询来实现
int ha(int *a) {
	int sum=0,mul=1;
	For(i,0,5) {
		sum=(sum+a[i])%mod;
		mul=(long long)mul*a[i]%mod;
	}
	return (sum+mul)%mod;
}
bool same(int *a,int *b) {
	For(i,0,5) For(j,0,5) {
		int flag=1;
		For(k,0,5) if(a[(i+k)%6]!=b[(j+k)%6]) flag=0;
		if(flag) return 1;
		flag=1;
		For(k,0,5) if(a[(i+k)%6]!=b[(j-k+6)%6]) flag=0;
		if(flag) return 1;
	}
	return 0;
}
bool insert(int *a) {
	int now=ha(a);
	for(int i=head[now]; i; i=nxt[i]) if(same(snow[i],a)) return 1;
	memcpy(snow[++tot],a,6*sizeof(int));//移动六个数
	nxt[tot]=head[now];
	head[now]=tot;//放到表头
	return 0;
}

inline int read() {
	int X=0,w=0;
	char ch=0;
	while(!isdigit(ch)) {
		w|=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w?-X:X;
}
signed main() {
	cin>>n;
	while(n--) {
		For(i,0,5) a[i]=read();
		if(insert(a)) {
			puts("Twin snowflakes found.");
			return 0;
		}
	}
	puts("No two snowflakes are alike.");
	return 0;
}
