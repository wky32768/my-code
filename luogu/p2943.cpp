#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=40005;
int n,m,t,a[N],pos[N],lst[N],nxt[N],pre[N],cnt[N],f[N];
/*
pos:之前第i个不同的数出现的额最后位置(倒着排)
lst:上一个a[i]出现的位置
cnt:从pos[j]到i的区间有多少个不同的数
*/
signed main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		pre[i]=lst[a[i]];
		nxt[lst[a[i]]]=i;
		lst[a[i]]=i;
		f[i]=0x3f3f3f3f;
		nxt[i]=n+1;
	}
	t=sqrt(n-1)+1;
	for(int i=1;i<=n;i++) pos[i]=1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=t; j++) {
			if(pre[i]<pos[j]) cnt[j]++;//有一个没有来过的
			if(cnt[j]>j) {//数量与i位置不对应，pos出现早了，需要把他变晚
				while(nxt[pos[j]]<i) pos[j]++;//使这个数只出现一次
				cnt[j]--;
				pos[j]++;//刚才这个位置的数是新来的，现在让他消失在区间里，所以要+1
			}
			f[i]=min(f[pos[j]-1]+j*j,f[i]);
		}
	cout<<f[n];
	return 0;
}
