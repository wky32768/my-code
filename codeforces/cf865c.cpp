#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,sxd,a[55],b[55];
double p[55];
double f[55][12000];
bool ok(double x) {
	//�۲����ʣ�Ҫô�Ǹ�ֵ��Ҫô����ǰһλ����������ҡ���Ϊÿһλ���������㣬���Բ��ø���ֵ(double����ֵ����0�Ļ��ͻ�ǳ������) 
	for(int i=n-1;i>=0;i--) {
        for(int j=sxd+1;j<=10000;j++) f[i+1][j]=x;//�����ˣ�û�н��׵�i(��Ȼ��i-1��Ҫ���õ��ˣ��ᵼ�´𰸴���) 
        for(int j=0;j<=sxd;j++) 
			f[i][j]=min(x,(f[i+1][j+a[i]]+a[i])*p[i]/100.0+(f[i+1][j+b[i]]+b[i])*(100.0-p[i])/100.0);
	}
    return (f[0][0]<x);
}
signed main() {
    cin>>n>>sxd;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>p[i];//��Ϊ�ǵ��ƣ�������ת��iʱ�õ���i-1 
    double l=0,r=1e18;
    for(int i=1;i<=150;i++) {
        double mid=(l+r)/2;
        if(ok(mid)) r=mid;
        else l=mid;
    }
    printf("%.10f",l);
    return 0;
}
