//��С����O(n^3)��1e5�����������־���Ҫç 
//���������£������� n �����������г��� 128 ����Ϊ 0 ��������ô��һ����3����Ϊ����128����Ϊ0����ʱ��64λÿһλ�ĸ�������2��ֻҪ�����������Ϊ0������������ִ���2��λ�������� 3 �Ļ���
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=130;
int n,cnt,tot,a[120000],b[120000],ans=2000000,dis[N][N],w[N][N];
signed main() {
	n=read();a
	For(i,1,n) {a[i]=read();if(a[i]>0) tot++;}
	if(tot>=129) return puts("3"),0;
	For(i,1,n) if(a[i]>0) b[++b[0]]=a[i];
	n=b[0];
	For(i,1,n) For(j,1,n) dis[i][j]=w[i][j]=2000000;
	For(i,1,n) For(j,1,n) if((b[i]&b[j])>0 && i!=j) dis[i][j]=w[i][j]=1;
	For(k,1,n) {
		For(i,1,k-1) For(j,i+1,k-1) ans=min(ans,dis[i][j]+w[j][k]+w[k][i]);
		For(i,1,n) For(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);	
	}
	cout<<((ans>0 && ans<=1000000)?ans:-1);
	return 0;
}

