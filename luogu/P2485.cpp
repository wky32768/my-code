#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,k,y,z,p;
int ksm(int a,int b,int mod) {
	int ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
void exgcd(int a,int b,int &x,int &y) {
	if(!b) {
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
void fc(int a,int b,int m) {
	int x,y,gg=__gcd(a,m);
	exgcd(a,m,x,y);
	if(b%gg!=0) {
		puts("Orz, I cannot find x!");
		return;
	}
	int sxd=m/gg;
	while(x<0) x+=sxd;
	cout<<(x*b/gg+sxd)%sxd<<'\n';
}
void bsgs(int a,int b,int m) {
	a%=m;
	b%=m;
	if(a==0) {
		if(b==0) {
			puts("1");
			return;
		} else {
			puts("Orz, I cannot find x!");
			return;	
		}
	}
	map <int,int> qls;
	qls.clear();
	int t=sqrt(m-1)+1;
	for(int j=0;j<t;j++) {
		int val=b*(ksm(a,j,m))%m;
		qls[val]=j;
	}
	a=ksm(a,t,m);
	for(int i=0;i<t;i++) {
		int val=ksm(a,i,m);
		int at=(qls.find(val)==qls.end()?-1:qls[val]);
		if(at!=-1 && i*t-at>=0) {
			cout<<i*t-at<<'\n';
			return;
		}
	}
	puts("Orz, I cannot find x!");
	return;
}
signed main() {
	cin>>t>>k;
	while(t--) {
		cin>>y>>z>>p;
		if(k==1) {
			cout<<ksm(y,z,p)<<'\n';
		} else if(k==2) {
			fc(y,z,p);
		} else if(k==3) {
			bsgs(y,z,p);
		}
	}
	return 0;
}
