#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
map <int,int> mp1,mp2;
int n,a[200005],ans=0x3f3f3f3f;
signed main() {
    n=read();
    For(i,1,n) a[i]=read();
    //把L到R的区间删掉
    For(l,1,n) {
        if(mp1[a[l-1]]==1) break;
        mp1[a[l-1]]=1;
        int r;
        mp2.clear();
        for(r=n;r>=l;r--) {
            if(mp1[a[r]] || mp2[a[r]]) break;
            mp2[a[r]]=1;
        }
        ans=min(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}