#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=2400000;
int ans,n,x,num[N],sum[N],pre,a;//pre���ǰһ����С�����м���,num��sum�е�ֵ�ĳ��ִ��� 
signed main() {
	cin>>n>>x;
	memset(sum,0,sizeof sum);
	memset(num,0,sizeof num);
	For(i,1,n) {
		cin>>a;
		sum[i+1000000]=sum[i-1+1000000]+(a>=x?1:-1);
	}
	/*
	pre���������棨������ǰһ����С�ģ���������������
	Ȼ������������˵������ǰһ��������preҪ����
	��ԭ�򣺴���>ǰһ������С��ǰһ����������pre���
	���ϵ��ڴ����������ֵĴ�����
	��֮��Ȼ��ֻҪ�ѼӺŸ�һ�¡�Ȼ��Ӵ���
	*/
	num[0+1000000]=1;
	For(i,1,n) {
		if(sum[i+1000000]>sum[i-1+1000000]) {//preӦ���ǵ�ǰ�ĺϷ������� 
			pre+=num[sum[i+1000000]+1000000]+1;
			//1:[i-1,i]
			//num[sum[i]]:֮ǰ�ﵽ���ڵ�ֵ�ĸ�����ԭ�Ȳ�һ���������Ѿ�����һ���������ֵ 
		} else pre-=num[sum[i-1+1000000]+1000000]-1;
		num[sum[i+1000000]+1000000]++;
		ans+=pre;
	}
	cout<<ans;
	return 0;
}
