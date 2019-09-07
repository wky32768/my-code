#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N =210000;
int n1,n2,a[N],ans,l[N],r[N],last=1;
char s[N],t[N];
signed main() {
    scanf("%s",s+1); scanf("%s",t+1);
    n1=strlen(s+1),n2=strlen(t+1);
    For(i,1,n1) {
        if(s[i]==t[last]) l[last]=i,last++;
        if(last==n2+1) break;
    }
    last=n2;
    for(int i=n1; i>=1; i--) {
        if(s[i]==t[last]) r[last]=i,last--;
        if(last==0) break;
    }
    ans=max(n1-l[n2],r[1]-1);
    For(i,2,n2) ans=max(ans,r[i]-l[i-1]-1);
    cout<<ans;
    return 0;
}
