#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,mx,a[1200000],ans[1200000],mp[1200000];
int read() {
    int x=0;
    char ch=getchar();
    while(!(ch>='0' && ch<='9')) ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x;
} 
void write(int x) {
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}
signed main(){ 
    scanf("%lld",&n);
    for(register int i=1;i<=n;i++) {
        a[i]=read();
        mp[a[i]]++;
        mx=max(mx,a[i]);
    }
    for(register int i=1;i<=mx;i++) if(mp[i]) {
        for(register int j=1;i*j<=mx;j++) ans[i*j]+=mp[i];
    }
    for(register int i=1;i<=n;i++) {
        write(ans[a[i]]-1);
        puts("");
    }
    return 0;
}