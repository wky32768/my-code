#include <bits/stdc++.h>
#define int long long
using namespace std;
map <int,int> mp;
int a,b,p,t;
int ksm(int a,int b) {
    int ans=1;
    while(b) {
        if(b&1) ans=(ans*a)%p;
        b>>=1;
        a=(a*a)%p;
    }
    return ans;
}
signed main() {
/*
a^x三b(mod p)
t=sqrt(p),x=i*t-j
a^(i*t-j)三b(mod p)
(a^t)^i三b*a^j(mod p)
*/
    cin>>p>>a>>b;
    t=sqrt(p-1)+1;
    for(int j=0;j<t;j++) {
        int val=b*ksm(a,j)%p; 
        mp[val]=j;
    }
    a=ksm(a,t);
    for(int i=0;i<=t;i++) {
        int val=ksm(a,i);
        int at=(mp.find(val)==mp.end()?-1:mp[val]);
        if(at!=-1 && i*t-at>=0) return cout<<i*t-at,0;
    }
    puts("no solution");
    return 0;
}