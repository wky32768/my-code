//a:一格管道的长度代价,b:支撑的单位长度代价
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N =200005;
int t,n,a,b,f[N][2];//以某一个数结尾的最小价值
char ch[N];
signed main() {
    t=read();
    while (t--) {
        n=read(),a=read(),b=read();
        scanf("%s",ch+1);
        memset(f,0x3f,sizeof f);
        f[0][0]=b;
        For(i,1,n) {
            if(ch[i]=='0') {
                f[i][1]=min(f[i][1],min(f[i-1][1]+a+2*b,f[i-1][0]+2*a+2*b));
                f[i][0]=min(f[i][0],min(f[i-1][1]+a*2+b,f[i-1][0]+a+b));
            } else {
                f[i][1]=min(f[i][1],f[i-1][1]+a+2*b);
            }
        }
        write(f[n][0]);
        puts("");
    }
    return 0;
}