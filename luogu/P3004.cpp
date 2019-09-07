#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,nn,x,a[5005],tot[3],q[5005],l=1,r=0,now=2,sum=0;
signed main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		q[++r]=a[i];
		sum+=a[i];
		while(r>=3 && q[r-1]>=q[r-2] && q[r-1]>=q[r]) {
			q[r-2]=q[r-2]+q[r]-q[r-1];//褰撳嚱鏁颁腑闂存湁涓�涓嘲鍑芥暟锛岀瓑浠蜂簬a1+a3-a2
			q[r-1]=q[r]=0;
			r-=2;
		}
	}
	while(l<=r) {
		now=3-now;
		if(l==r) {
			tot[now]+=q[l];
			l++;
		} else if(q[l]>q[r]) {
			tot[now]+=q[l];
			l++;
		} else {
			tot[now]+=q[r];
			r--;
		}
	}
	cout<<(tot[1]-tot[2]+sum)/2;
	/*
	解释一下
	这里的tot[1]和tot[2]是相对的差（就是能够占别人多少便宜
	先把两边相互抵消
	a-b=tot[1]-tot[2]
	a+b=sum
	求解二元一次方程组即可 
	*/
	return 0;
}
