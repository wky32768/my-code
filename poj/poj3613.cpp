//先算出一次的最短路，然后模仿矩阵乘法来累加,然后比如算两次的时候，就相当于把两个一次的答案相加
#include <bits/stdc++.h>
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int n, t, x, y, cnt, aa, bb, cc;
map<int, int> mp;
struct mat {
    int a[230][230];
} ss, tt;
mat mul(mat a, mat b) {
    mat c;
    memset(c.a, 0x3f, sizeof c.a);
    For(i, 1, cnt) For(j, 1, cnt) For(k, 1, cnt) c.a[i][j] =
        min(c.a[i][j], a.a[i][k] + b.a[k][j]);
    return c;
}
signed main() {
    cin >> n >> t >> x >> y;
    memset(ss.a, 0x3f, sizeof ss.a);
    while (t--) {
        cin >> cc >> aa >> bb;
        aa = mp[aa] ? mp[aa] : (mp[aa] = ++cnt);
        bb = mp[bb] ? mp[bb] : (mp[bb] = ++cnt);
        ss.a[aa][bb] = ss.a[bb][aa] = cc;
    }
    memcpy(tt.a, ss.a, sizeof ss.a);
    n--;
    while (n) {
        if (n & 1)
            tt = mul(tt, ss);
        ss = mul(ss, ss);
        n >>= 1;
    }
    cout << tt.a[mp[x]][mp[y]];
    return 0;
}