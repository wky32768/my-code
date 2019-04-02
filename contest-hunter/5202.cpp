#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, f[120000];
signed main() {
    f[0] = 1;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            f[j] = (f[j] + f[j - i]) % 2147483648;
    cout << (f[n] - 1) % 2147483648;
    return 0;
}