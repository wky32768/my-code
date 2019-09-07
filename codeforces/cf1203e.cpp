#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N =180000;
int n,a[N],ans,last=0;
signed main() {
    n=read();
    For(i,1,n) a[i] = read();
    sort(a+1,a+n+1);
    For(i,1,n) {
        if(a[i]-1>last) {
            ans++;
            last=a[i]-1;
        } else if(a[i]>last) {
            ans++;
            last=a[i];
        } else if(a[i]+1>last) {
            ans++;
            last=a[i]+1;
        }
    }
    cout<<ans;
    return 0;
}