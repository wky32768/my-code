/*
x,y ��Ϊ��������ô lcm(x, y)�϶������������Կ���
x, y Ϊһ��һż����ôlcm(x,y) Ϊż�������Բ��С�
x, y ��Ϊż��������ת��Ϊǰ�������������lcm��ʹ����2�����൱�ڰ�������������2
����ֻҪ������������ͬλ�����㼴�ɡ� 
*/
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int n,a[200005],tot[200005],tong[105],mx,mxat,now;
signed main() {
	n=read();
	For(i,1,n) {
		a[i]=read(); now=a[i];
		while(now && now%2==0) {
			tot[i]++;
			now/=2;
		}
		tong[tot[i]]++;
		if(tong[tot[i]]>mx) mx=tong[tot[i]],mxat=tot[i];
	}
	write(n-mx); puts("");
	For(i,1,n) if(tot[i]!=mxat) write(a[i]),putchar(' ');
	return 0;
}

