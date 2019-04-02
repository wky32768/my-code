#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b,x,y;
void exgcd(int a,int b,int &x,int &y) {
    if(b==0) {
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=(a/b)*x;
}
signed main() {
    scanf("%lld%lld",&a,&b);
    exgcd(a,b,x,y);
    while(x<0) x+=b;
    printf("%lld",x);
    return 0;
}