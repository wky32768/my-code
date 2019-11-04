#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
stack <int> st;
char ch[200005];
int l,r,n,ans;
signed main() {
	cin>>n;
	scanf("%s",ch+1);
	For(i,1,n) {
		if(ch[i]=='(') l++;
		else r++;
	}
	if(l!=r) return puts("No"),0;
	For(i,1,n) {
		if(ch[i]=='(') st.push(1);
		else {
			if(!st.empty()) {
				st.pop();
				ans+=2;	
			}
		}
	}
	if(ans==n || ans==n-2) puts("Yes");
	else puts("No");
	return 0;
}

