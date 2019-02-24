//求异或能够达到的最大值 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[12000],ji[12000];
bool cmp(int x,int y) {
	return x>y;
}
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
//	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=62;j>=0;j--) 
			if((a[i]>>j)&1) {
				if(!ji[j]) {
					ji[j]=a[i];
					break;
				}
				a[i]^=ji[j];
			}
	int ans=0;
	for(int i=62;i>=0;i--) if((ans^ji[i])>ans) ans=ans^ji[i];
	cout<<ans;
	return 0;
}
