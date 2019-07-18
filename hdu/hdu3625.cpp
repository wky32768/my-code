/*
第一类斯特林数：𝑠_𝑢 (𝑛+1,𝑚)=𝑠_𝑢 (𝑛,𝑚−1)+𝑛𝑠_𝑢 (𝑛,𝑚)
门和钥匙的对应关系是个排列，排列是一个一个的环，
其中每个环炸一次就可以把环取完，所以题目的要求就是n！个排列中组成<=k个环的排列数量，
这就是第一类斯特林数的定义
根据定义修改公式
*/
#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int su[23][23],t,n,k,fac[23];
void init() {
    su[0][0]=1;
    For(i,1,20) For(j,1,20) su[i][j]=su[i-1][j-1]+(i-1)*su[i-1][j];
}
double solve(int n,int k) {
    int ans=0;
    For(i,1,k) ans+=(su[n][i]-su[n-1][i-1]);
    return (double)ans/(double)fac[n];
}
signed main() {
    //sxdaknoi
    init();
    cin>>t;
    fac[0]=1;
    For(i,1,20) fac[i]=fac[i-1]*i;
    while(t--) {
        cin>>n>>k;
        printf("%.4f\n",solve(n,k));
    }

}