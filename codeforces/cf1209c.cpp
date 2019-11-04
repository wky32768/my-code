#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=200005;
int t,n,ans[N];
char ch[N];
signed main() {
	t=read();
	while(t--) {
		n=read();
		scanf("%s",ch+1);
		For(fen,0,9) {
//			cout<<"fen="<<fen<<'\n';
			int last1=0,last2=0,fir1=0,fir2=0;
			For(i,1,n) {
				int now=ch[i]-'0';
//				cout<<"last1&last2: "<<last1<<" "<<last2<<" "<<fir2<<" "<<now<<'\n';
				if(now>=fen) {
					if(last2>now) {
						if(now==fen && fir2==now)
							last1=now,ans[i]=1;
						else goto L2;
					}
					else {
						if(last2==0) fir2=now;
						last2=now,ans[i]=2;
					}
				} 
				else {
					if(last1>now) goto L2;	
					else last1=now,ans[i]=1;
				}
			}
			For(i,1,n) cout<<ans[i]; 
			puts("");
			goto L1;
			L2:;
		}
		puts("-");
		L1:;
	}
	return 0;
}

