//高精度不够快，这里有一种非常精妙的球卡特兰数的方法，就是枚举中间的质数，算出每个质数出现了多少次，然后高精度乘法即可
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans[1200000],len=1,p[1200000],c[1200000],tot;
bool vis[1200000];
void jing(int x) {
	for(int i=1;i<=len;i++) ans[i]*=x;
	len+=6;//最多加六位（*的数小于等于n*2）
	for(int i=1;i<=len;i++) {
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	while(!ans[len]) len--;
}
signed main() {
	cin>>n;
	ans[1]=1;
	for(int i=2;i<=n*2;i++) if(!vis[i]) {
		p[++tot]=i;
		for(int j=i;j<=120000;j+=i) vis[j]=1;
	}//埃氏筛
	for(int i=1;i<=tot;i++) {
		int now=p[i];
		while(now<=n*2) {//c[i]指出现的个数
			c[i]+=n*2/now-n/now-(n+1)/now;
			now*=p[i];
		}
		while(c[i]--) jing(p[i]);
	}
	for(int i=len;i>=1;i--) cout<<ans[i];
	return 0;
}