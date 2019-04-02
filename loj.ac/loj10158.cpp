#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,w[120],mid[120][120],f[120][120];
int dfs(int l,int r) {
	if(l>r) return 1;
	/*
	这句非常的精妙，为什么呢?
	我本来是把下面的for循环从l-1到r的
	可是这样会漏掉只有一个子树的情况
	所以这个也是要注意的
	要想到特殊的情况
	*/
	if(f[l][r]) return f[l][r];
	if(l==r) {
		mid[l][r]=l;
		f[l][r]=w[l];
		return w[l];
	}
	for(int i=l;i<=r;i++) {
		int now=dfs(l,i-1)*dfs(i+1,r)+w[i];
		if(now>f[l][r]) {
			f[l][r]=now;
			mid[l][r]=i;
		}
	}
	return f[l][r];
}
void print(int l,int r) {
	if(l>r || !mid[l][r]) return;
	if(l==r) {
		cout<<l<<" ";
		return;
	}
	cout<<mid[l][r]<<" ";
	print(l,mid[l][r]-1);
	print(mid[l][r]+1,r);
	return;
}
signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	cout<<dfs(1,n)<<'\n';
	print(1,n);
	return 0;
}