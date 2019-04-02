/*用记忆化搜索实现对子树的计数*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9;
int n,f[320][320];
char ch[120000];
int solve(int l,int r) {
    if(l==r) return 1;
    if(f[l][r]!=-1) return f[l][r];
    f[l][r]=0;
    if(ch[l]==ch[r]) for(int k=l+1;k<=r-1;k++) f[l][r]=(f[l][r]+solve(l+1,k)*solve(k+1,r))%mod;//要留一边开始或结束
    return f[l][r];
}
signed main() {
    scanf("%s",ch+1);
    n=strlen(ch+1);
    memset(f,-1,sizeof f);//与0相区分
    solve(1,n);
    printf("%lld",f[1][n]);
    return 0;
}