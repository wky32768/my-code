//����һ���Ӻ���ǰ�ң��ҵ���һ��Ϊ0��λ�ã�����ȷ����λ��Ϊ1���Ӹ�λ������� ������ ����ȥ1,
//�ٴδӺ���ǰ��0��ȷ����λ��Ϊ2�������ĺ����ж���ȥ2,ֱ������λ�ö���ȷ����
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=200005;
int n,w[N],a[N],tree[N<<2];
int nn;
bool vis[N];
#define lowbit(x) (x&(-x))
inline void add(int x,int C) {for(int i=x;i<=n;i+=lowbit(i)) tree[i]+=C;}
inline int tot(int x) {
	int tot=0;
	for(int i=x;i;i-=lowbit(i)) tot+=tree[i];
	return tot;
}
signed main() {
	n=read();
	For(i,1,n) w[i]=read();
	For(i,1,n) add(i,i);
	for(int i=n;i>=1;i--) {
		int l=1,r=n,ans=0;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(tot(mid)>w[i]) {
				r=mid-1;	
			} else {
				ans=mid;
				l=mid+1;	
			}
		}
		if(!ans) {
			while(vis[ans]) ans++;
		}
		ans++;
		a[i]=ans;
		vis[a[i]]=1;
		add(a[i],-a[i]);
	}
	For(i,1,n) cout<<a[i]<<" ";
	return 0;
}
