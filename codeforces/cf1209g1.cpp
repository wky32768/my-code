//Ԥ��������ÿ��Ԫ����������ȵ�Ԫ�������ҵ�һ������������һ����һ�� block��
//���ֳ����е� block ��ÿ�� block ������
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
const int N=200005;
int n,q,a[N],last[N],tot[N],f[N],ans;//f:һ���е����һλ 
signed main() {
	n=read(),q=read();
	ans=n;
	For(i,1,n) {
		a[i]=read();
		tot[a[i]]++;
		last[a[i]]=i;
	}
	For(i,1,n) f[i]=max(last[a[i]],f[i-1]);//��һ�֣�������������һλ���ڶ��֣�ǰ������˺����һλҪ����һ��
	int l=1;
	For(i,1,n) if(f[i]==i) {
		int mx=0;
		For(j,l,i) mx=max(mx,tot[a[j]]);	
		ans-=mx;//�ٻ�������ô�ࣨ���ö��� 
		l=i+1;
	}
	cout<<ans;
	return 0;
}

