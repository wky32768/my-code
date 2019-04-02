//神仙结论，还是去看证明吧
#include <bits/stdc++.h>
#define int long long
using namespace std;
int ksc(int a, int b, int mod) {
    int ans = 0;
    while (b) {
        if (b & 1)
            ans = (ans + a) % mod;
        b >>= 1;
        a = a * 2 % mod;
    }
    return ans;
}
int ksm(int a, int b, int mod) {
    int ans = 1 % mod;//k可能=1
    while (b) {
        if (b & 1)
            ans = ksc(ans, a, mod);
        b >>= 1;
        a = ksc(a, a, mod);
    }
    return ans;
}
int phi(int x) {
    int ans = x;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) {
            ans = ans / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        ans = ans / x * (x - 1);
    return ans;
}
int n, cnt;
int solve() {
    int d = __gcd(n, 8ll);
    int k = 9ll * n / d;
    if(__gcd(k,10ll)!=1) return 0;//剪枝
    int p = phi(k);
    for (int i = 1; i <= sqrt(p); i++)
        if (p % i == 0 && ksm(10ll, i, k) == 1)
            return i;
    for (int i = sqrt(p) - 1; i >= 1; i--)
        if (p % (p / i) == 0 && ksm(10ll, p / i, k) == 1)
            return p/i;
    return 0;
}
signed main() {
    while (scanf("%lld", &n) && n)
        printf("Case %lld: %lld\n", ++cnt, solve());
    return 0;
}