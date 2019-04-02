// 01背包
#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int n, m, a[12000], f[120000], ans;
signed main() {
    scanf("%lld%lld", &n, &m);
    For(i, 1, n) scanf("%lld", &a[i]);
    f[0] = 1;
    For(i, 1, n) for (int j = m; j >= a[i]; j--) f[j] += f[j - a[i]];
    cout << f[m];
    return 0;
}