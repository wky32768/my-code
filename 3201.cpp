#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, d, ans;
inline int read() {
    int x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) {
        f |= (ch == '-');
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f ? -x : x;
}
inline void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}
inline int gcd(int x,int y) {
    if(x<y) swap(x,y);
    int z=x%y;
    while(z) {
        x=y;
        y=z;
        z=x%y;
    }
    return y;
}
inline long long lcm(int x, int y) { return (long long)x / gcd(x, y) * y; }
signed main() {
    scanf("%lld", &t);
    while (t--) {
        a=read(),b=read(),c=read(),d=read();
        ans = 0;
        for (register int i = 1; i * i <= d; i++)
            if (d % i == 0) {
                if (gcd(a, i) == b && lcm(c, i) == d)
                    ans++;
                if (i * i != d && (gcd(a, d / i) == b && lcm(c, d / i) == d))
                    ans++;
            }
        write(ans);
        puts("");
    }
    return 0;
}