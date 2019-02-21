//先建树，然后尽量按照相反进行搜索（因为这样异或以后就是1了）
#include <bits/stdc++.h>
#define int long long
using namespace std;
int trie[5200000][5],x;
int n,ans,cnt=0;
void insert(int x) {
	int p=0;
	for(int k=30;k>=0;k--) {
		int now=(x>>k)&1;
		if(trie[p][now]==0) trie[p][now]=++cnt;
		p=trie[p][now];
	}
}
int solve(int x) {
	int p=0,ans=0;
	for(int k=30;k>=0;k--) {
		int now=(x>>k)&1;
		if(trie[p][now^1]) {
			p=trie[p][now^1];
			ans|=1<<k;
		} else p=trie[p][now];
	}
	return ans;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>x;
		insert(x);
		ans=max(ans,solve(x));
	}
	cout<<ans;
	return 0;
}