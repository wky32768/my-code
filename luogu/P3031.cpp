#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=2400000;
int ans,n,x,num[N],sum[N],pre,a;//pre存比前一个数小的数有几个,num是sum中的值的出现次数 
signed main() {
	cin>>n>>x;
	memset(sum,0,sizeof sum);
	memset(num,0,sizeof num);
	For(i,1,n) {
		cin>>a;
		sum[i+1000000]=sum[i-1+1000000]+(a>=x?1:-1);
	}
	/*
	pre就是用来存（（（比前一个数小的）的数）的数量）
	然后对于这个数来说，若比前一个数大，那pre要增加
	（原因：此数>前一数，且小于前一数的数量在pre里）再
	加上等于此数的数出现的次数。
	反之亦然，只要把加号改一下。然后加答案里
	*/
	num[0+1000000]=1;
	For(i,1,n) {
		if(sum[i+1000000]>sum[i-1+1000000]) {//pre应该是当前的合法区间数 
			pre+=num[sum[i+1000000]+1000000]+1;
			//1:[i-1,i]
			//num[sum[i]]:之前达到现在的值的个数，原先差一个，现在已经满足一样且是最大值 
		} else pre-=num[sum[i-1+1000000]+1000000]-1;
		num[sum[i+1000000]+1000000]++;
		ans+=pre;
	}
	cout<<ans;
	return 0;
}
