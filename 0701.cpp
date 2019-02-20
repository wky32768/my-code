//别人家的高精度。。。（委屈）
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {
	int a,b,c;
} x[1200];
const int N=210000;
int now[N],sum[N],ans[N],add[N];
void cheng(int x) {
	memset(add,0,sizeof add);
	for(int i=1;i<=ans[0];i++) {
		ans[i]=ans[i]*x;
		add[i+1]+=ans[i]/10;
		ans[i]%=10;	
	}
	for(int i=1;i<=ans[0]+4;i++) {
		ans[i]+=add[i];
		if(ans[i]>10) {
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		if(ans[i]) ans[0]=max(ans[0],i);
	}
	return;
}
int chu(int x) {
	memset(add,0,sizeof add);
	int q=0;
	for(int i=ans[0];i>=1;i--) {
		q*=10;
		q+=ans[i];
		add[i]=q/x;
		if(add[0]==0 &&add[i]!=0) add[0]=i;
		q%=x;
	}
	return 0;
}
bool compare() {
	if(sum[0]==add[0]) {
		for(int i=add[0];i>=1;i--) if(add[i]!=sum[i]) return add[i]>sum[i];
	}
	return add[0]>sum[0];
}
void copy() {
	memset(sum,0,sizeof sum);
	for(int i=add[0];i>=0;i--) sum[i]=add[i];
}
bool cmp(node x,node y) {
	return x.a*x.b<y.a*y.b;
}
int n;
signed main() {
	cin>>n;
	for(int i=0;i<=n;i++) cin>>x[i].a>>x[i].b;
	sort(x+1,x+n+1,cmp);
	ans[0]=ans[1]=1;
	for(int i=1;i<=n;i++) {
		cheng(x[i-1].a);
		chu(x[i].b);
		if(compare()) copy();
	}
	for(int i=sum[0];i>=1;i--) cout<<sum[i];
	return 0;
}