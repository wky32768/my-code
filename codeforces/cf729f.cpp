#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=4005;
int n,a[N],sum[N],f[50000005];//左侧第一个未娶的数在第i个，右侧第一个是a,i-a=j,当前的k，操作方(0左1右)
int h(int l,int r,int k,int now) {return ((((l*4000)+r)*100+k)*2+now)%50000000;}//这样不用进行状态的转移
int dfs(int l,int r,int k,int now) {
    if(r-l+1<k) return 0;//剪枝1
    if(r-l+1==k) {
        if(now==0) {
            // cout<<"debug1 "<<l<<" "<<r<<" "<<k<<" "<<now<<" "<<sum[r]-sum[l-1]<<'\n';
            return sum[r]-sum[l-1]; 
        }
        else {
            // cout<<"debug2 "<<l<<" "<<r<<" "<<k<<" "<<now<<" "<<sum[l-1]-sum[r]<<'\n';
            return sum[l-1]-sum[r];
        }
    }//剪枝2
    if(f[h(l,r,k,now)]!=-0x3f3f3f3f) {
        return f[h(l,r,k,now)];
    }
    if(now==0) {
        int count=dfs(l+k,r,k,1)+sum[l+k-1]-sum[l-1];
        if(l+k<=r) count=max(count,dfs(l+k+1,r,k+1,1)+(sum[l+k]-sum[l-1]));//拉大差距
        f[h(l,r,k,now)]=count;
        // cout<<"debug3 "<<l<<" "<<r<<" "<<k<<" "<<now<<" "<<count<<'\n';
        return count;
    } else if(now==1) {
        int count=dfs(l,r-k,k,0)-(sum[r]-sum[r-k]);
        if(l+k<=r) count=min(count,dfs(l,r-k-1,k+1,0)-(sum[r]-sum[r-k-1]));//缩小差距
        f[h(l,r,k,now)]=count;
        // cout<<"debug4 "<<l<<" "<<r<<" "<<k<<" "<<now<<" "<<count<<'\n';
        return count;
    }
}
signed main() {
    cin>>n;
    For(i,1,n) cin>>a[i];
    For(i,1,n) sum[i]=sum[i-1]+a[i];
    For(i,1,50000000) f[i]=-0x3f3f3f3f;
    cout<<dfs(1,n,1,0);
    return 0;
}