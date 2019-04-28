/*
详见《算进》P175
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=51000;
int t,miu[51002],sum[51002],x,y,k,ans;
bool vis[51002];
void mo() {
    for(int i=1;i<=N;i++) miu[i]=1;
    for(int i=2;i<=N;i++) {
        if(vis[i]) continue;
        miu[i]=-1;//质数
        for(int j=i*2;j<=N;j+=i) {
            vis[j]=1;
            if((j/i)%i==0) miu[j]=0;
            else miu[j]*=-1;
        }
    }
    for(int i=1;i<=N;i++) sum[i]=sum[i-1]+miu[i];
}//构造莫比乌斯函数
signed main() {
    cin>>t;
    mo();
    while(t--) {
        scanf("%lld%lld%lld",&x,&y,&k);
        int l=1,r=0;
        ans=0;
        for(;l<=min(x,y);l=r+1) {
            /*
            对于每一个⌊n/i⌋我们可以通过打表(或理性的证明)可以发现：
            有许多⌊ni⌋的值是一样的，而且它们呈一个块状分布；
            再通过打表之类的各种方法,我们惊喜的发现对于每一个值相同的块，它的最后一个数就是n/(n/i)。
            得出这个结论后，我们就可以做的O(n*sqrt(n))处理了。
            */
            r=min(x/(x/l),y/(y/l));
            ans+=(sum[r]-sum[l-1])*((x/k)/l)*((y/k)/l);
        }
        cout<<ans<<'\n';
    }
    return 0;
}