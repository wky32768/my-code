#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N =1200;
char ch[N];
int n,ans,all_zero=1;
signed main() {
    scanf("%s",ch+1);
    n=strlen(ch+1);
    For(i,2,n) if(ch[i]!='0') all_zero=0;
    cout<<(n+1)/2-(all_zero && n%2==1);
    return 0;
}