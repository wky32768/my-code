#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
#define ny(x) (ksm(x, mod - 2))
#define debug(x) cout << "debug " << x << '\n';
using namespace std;
int read() {
    int x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch))
        f |= (ch == '-'), ch = getchar();
    while (isdigit(ch))
        x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
const int N = 1200000;
const int mod = 998244353;
int n, ans, times[N], fac[N];
inline int ksm(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
inline int C(int n, int m) {
    return fac[n] * ny(fac[m]) % mod * ny(fac[n - m]) % mod;
}
signed main() {
    cin >> n;
    times[0] = fac[0] = 1;
    For(i, 1, 1000000) {
        times[i] = (times[i - 1] * 3ll) % mod;
        fac[i] = fac[i - 1] * i % mod;
    }
    ans = ksm(3,n*n); //乱选
    ans = (ans - ksm(times[n] - 3, n) + mod) % mod;
    /*
    每一列都有两个（但这时可能有行中有一个，接下来要去掉这些情况
    1.选出来的i行的颜色(每行都是相同的h)有任意两个不同
    这样先枚举这些行的颜色，然后计算剩下的乱选，然后^n
    2.选出来的ii行的颜色两两相同
    每一列都是其他乱选，可是不能所有颜色都和行里统一的颜色一样，然后*3种不同的行里颜色数
    */
    For(i, 1, n) {
        int zf = (i % 2 == 0 ? -1 : 1) * C(n, i);
        ans = (ans + (times[i] - 3) * (ksm(3,(n-i)*n)) % mod * zf + mod) % mod;
        ans = (ans + 3 * (ksm(times[n - i] - 1, n)) * zf + mod) % mod;
    }
    cout << ans;
    return 0;
}
