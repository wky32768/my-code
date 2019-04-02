/*
数位DP
https://img-blog.csdn.net/20171022220207891?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQva29uZ2hoaGho/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[52][52], x, y, k, c;
/*f[i][j] 前i个中j个1的个数*/
vector<int> v;
void pre() {
    f[0][0] = 1;
    for (register int i = 1; i <= 32; i++) {
        f[i][0] = f[i - 1][0];
        for (int j = 1; j <= i; j++)
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1]; /*选1，不选1*/
    }
}
/*相当于在一颗树中进行操作*/
int solve(int x, int k, int c) {
    v.clear();
    while (x) {
        v.push_back(x % c);
        x /= c;
    }
    int cnt = 0, ans = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] == 1) {
            ans += f[i][k - cnt];
            // cout<<"f["<<i<<"]["<<k-cnt<<"]="<<f[i][k-cnt]<<'\n';
            cnt++;
            if (cnt == k)
                break;
        } else if (v[i] > 1) {
            /*假如大于1的话，相当于所有的位有可以为1，所以直接求解跳出*/
            ans += f[i + 1][k - cnt];
            break;
        }
    }
    return (cnt == k) ? ans + 1 : ans;
    /*最后要算上自己*/
}
signed main() {
    pre();
    while (scanf("%lld%lld%lld%lld", &x, &y, &k, &c)!=EOF) {
        printf("%lld\n", solve(y, k, c) - solve(x - 1, k, c));
    }
    return 0;
}