#include <bits/stdc++.h>
#define For(i, a, b) for (register int i = a; i <= b; i++)
#define int long long
using namespace std;
int n, a[120], sum[120], he, ans;
signed main() {
    cin >> n;
    For(i, 1, n) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        he += a[i];
    }
    For(i, 1, n) For(j, i + 1, n) {
        if (sum[j] - sum[i] == he / 2)
            ans++;
    }
    cout << ans * (ans - 1) / 2;
    return 0;
}