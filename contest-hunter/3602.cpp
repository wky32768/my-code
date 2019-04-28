#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 120000;
int n, t, f[N], a[N], huan[N], cnt, fac[N];
bool vis[N];
const int mod = 1e9 + 9;
int ksm(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
signed main() {
    f[1]=1;
    for (int i = 2; i <= 120000; i++) {
        f[i] = ksm(i, i - 2);
    }
    fac[0]=fac[1] = 1;
    for (int i = 2; i <= 120000; i++)
        fac[i] = fac[i - 1] * i % mod;
    cin >> t;
    while (t--) {
        cin>>n;
        for (int i = 1; i <= n; i++)
            cin>>a[i];
        memset(vis, 0, sizeof vis);
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i])
                continue;
            int now = 0;
            while (!vis[i]) {
                vis[i] = true;
                now++;
                i = a[i];
            }
            huan[++cnt] = now;
        }
        int ans = fac[n - cnt];
        for (int i = 1; i <= cnt; i++)
            ans = (ans * f[huan[i]]) % mod;
        for (int i = 1; i <= cnt; i++)
            ans = (ans * ksm(fac[huan[i]-1], mod - 2)) % mod;
        cout << ans << '\n';
    }
    return 0;
}