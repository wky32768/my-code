#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, num[1200],sum[1200],dp[5200][5200],ans[1200];
struct node {
    int n, m;
} pre[1200][1200];
struct child {
    int g, id;
} ch[1200];
bool cmp(child a, child b) { return a.g > b.g; }
void gui(int i,int j) {
    if(i==0) return;
    gui(pre[i][j].n,pre[i][j].m);
    if(pre[i][j].n==i) for(int k=1;k<=i;k++) ans[ch[k].id]++;//对应第一种情况，给每一个前面的值都+1
    else for(int k=pre[i][j].n+1;k<=i;k++) ans[ch[k].id]=1;//对应第二种情况，前面有一堆的1[(i-k)的计算当然都是1了啊]
}
void solve() {
    for(int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+ch[i].g;//前缀和
        for(int j=i;j<=m;j++) {
            dp[i][j]=dp[i][j-i];//第一种情况：等价于所有前面的值都减一，相对位置不变，答案也不变
            pre[i][j]=(node) {i,j-i};//储存上一个的信息，方便输出
            // cout<<"dp[i][j]="<<dp[i][j]<<'\n';
            for(int k=0;k<i;k++) {//枚举几个人的分数跟之前一样
                if(dp[i][j]>dp[k][j-(i-k)]+k*(sum[i]-sum[k])) {
                    dp[i][j]=dp[k][j-(i-k)]+k*(sum[i]-sum[k]);//第二种情况，前面有一一堆
                    pre[i][j]=(node) {k,j-(i-k)};
                }
            }
        }
    }
    cout<<dp[n][m]<<'\n';
    gui(n,m);
    for(int i=1;i<=n;i++) {
        cout<<ans[i];
        if(i==n) puts("");
        else cout<<" ";
    }
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> ch[i].g;
        ch[i].id = i;
    }
    sort(ch + 1, ch + n + 1, cmp);
    memset(dp,0x3f,sizeof dp);
    dp[0][0]=0;
    solve();
}