//数位DP
#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int a, b, cnt, sum, wei[120], f[120][120]; // i位,第一位是j
int find(int x) {
    cnt = sum = 0;
    for (int i = x; i; i /= 10)
        wei[++cnt] = i % 10;
    For(i, 1, cnt - 1) For(j, 1, 9) sum += f[i][j]; //长度小于x的
    For(i, 1, wei[cnt]-1) sum += f[cnt][i]; //长度相等，高位小于x的
    for (int i = cnt, mx = 0; i >= 1;
         i--) { //枚举相等的位，求长度相等，若干高位相等且小于x的
        if (wei[i - 1] < wei[i])
            break;
        mx = max(mx, wei[i]);
        For(j, mx, wei[i - 1] - 1) sum += f[i - 1][j];
    }
    return sum;
}
signed main() {
    For(i, 0, 9) f[1][i] = 1;
    For(i, 2, 20) For(j, 1, 9) For(k, j, 9) f[i][j] +=
        f[i - 1][k]; //根据提议易得
    while (scanf("%lld%lld", &a, &b) != EOF)
        cout << find(b+1) - find(a) << '\n';
    return 0;
}