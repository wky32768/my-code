#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m,t,hang[120000],lie[120000],he1[120000],he2[120000],ok1,ok2,ans;
signed main() {
	cin>>n>>m>>t;
	for(int i=1; i<=t; i++) {
		int x,y;
		cin>>x>>y;
		hang[x]++;
		lie[y]++;
	}
	int sum1=0,sum2=0;
	For(i,1,n) sum1+=hang[i];
	if(sum1%n==0) ok1=1;
	For(i,1,m) sum2+=lie[i];
	if(sum2%m==0) ok2=1;
	
	if(ok1 && ok2) cout<<"both ";
	else if(ok1 && (!ok2)) cout<<"row ";
	else if((!ok1) && ok2) cout<<"column ";
	else {
		cout<<"impossible";
		return 0;
	}
	if(ok1) {
		For(i,1,n) hang[i]-=sum1/n;
		For(i,1,n) he1[i]=he1[i-1]+hang[i];
		sort(he1+1,he1+n+1);
		int k=he1[(n+1)/2];
		For(i,1,n) ans+=abs(he1[i]-k);
	}
	if(ok2) {
		For(i,1,m) lie[i]-=sum2/m;
		For(i,1,m) he2[i]=he2[i-1]+lie[i];
		sort(he2+1,he2+m+1);
		int k=he2[(m+1)/2];
		For(i,1,m) ans+=abs(he2[i]-k);
	}
	cout<<ans;
	return 0;
}

