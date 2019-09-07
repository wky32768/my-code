//单调队列优化DP，要先退出关系式，存在寻找某一个区间的最大值，所以最后维护最大值即可，队列单调递减
#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=100005;
int a[N],f[N],q[N],n,k,sum[N],l=1,r=1;//f:前i头牛，第i头不选
signed main() {
    cin>>n>>k;
    For(i,1,n) cin>>a[i],sum[i]=sum[i-1]+a[i];
    For(i,1,n+1) {
        while(l<=r && q[l]<i-1-k) l++;//连续的长度超标
        f[i]=f[q[l]]-sum[q[l]]+sum[i-1];
        while(l<=r && f[i]-sum[i]>=f[q[r]]-sum[q[r]]) r--;//最右边的值太小了
        q[++r]=i;
    }
    cout<<f[n+1];
    return 0;
}
