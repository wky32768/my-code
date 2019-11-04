#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int n;
char ch1[200005],ch2[200005];
int c,d;//ab,ba;
int num1[200005],num2[200005];
signed main() {
	cin>>n;
	scanf("%s",ch1+1);
	scanf("%s",ch2+1);
	For(i,1,n) {
		if(ch1[i]=='a' && ch2[i]=='b') c++,num1[c]=i;
		else if(ch1[i]=='b' && ch2[i]=='a') d++,num2[d]=i;
	}
	if((c+d)%2==1) return puts("-1"),0;
	int ans=0;
	if(c%2==0) ans=c/2+d/2;
	else ans=(c-1)/2+(d-1)/2+2;
	cout<<ans<<'\n';
	for(int i=1;i<c;i+=2) cout<<num1[i]<<" "<<num1[i+1]<<'\n';
	for(int i=1;i<d;i+=2) cout<<num2[i]<<" "<<num2[i+1]<<'\n';
	if(c%2!=0) {
		cout<<num2[d]<<" "<<num2[d]<<'\n';
		cout<<num2[d]<<" "<<num1[c]<<'\n';	
	}
	return 0;
}
