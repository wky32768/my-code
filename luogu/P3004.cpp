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
			q[r-2]=q[r-2]+q[r]-q[r-1];//当函数中间有一个峰函数，等价于a1+a3-a2
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
	����һ��
	�����tot[1]��tot[2]����ԵĲ�����ܹ�ռ���˶��ٱ���
	�Ȱ������໥����
	a-b=tot[1]-tot[2]
	a+b=sum
	����Ԫһ�η����鼴�� 
	*/
	return 0;
}
