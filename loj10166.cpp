#include <bits/stdc++.h>
#define int long long
using namespace std;
/*f[i][j][k]i位最高j和为k*/
int f[23][23][120], l, r, x, len, sum, he, bei, wei[120];
void pre() {
    for (int i = 0; i <= 9; i++)
        f[1][i][i] = 1;
    for (int i = 2; i <= 10; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                for (int he = 0; he <= 100; he++)
                    f[i][j][j + he] += f[i - 1][k][he];
}
int solve(int x, int mod) {
    // cout<<"solve "<<x<<'\n';
    len = sum = he = 0;
    bei = 90 / mod;
    while (x) {
        wei[++len] = x % 10;
        x /= 10;
    }
    for (int i = len; i >= 1; i--) {
        for (int j = 0; j <= wei[i] - 1; j++)
            for (int k = 1; k <= bei; k++) {
                // cout<<"add "<<i<<" "<<j<<" "<<k*mod-he<<" "<<f[i][j][k*mod-he]<<'\n';
                sum += f[i][j][k * mod - he];
            }
        he = (he + wei[i]) % mod;
    }
    return sum;
}
signed main() {
    pre();
    while (scanf("%lld%lld%lld", &l, &r, &x) != EOF) {
        cout << solve(r + 1, x) - solve(l, x) << '\n';
    }
}