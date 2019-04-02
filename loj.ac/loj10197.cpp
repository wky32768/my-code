#include <bits/stdc++.h>
#define int long long
using namespace std;
int prime[655370], cnt, l, r;
bool ok[655370], a[1000010];
void shai() {
    for (register int i = 2; i * i <= r; i++) {
        if (ok[i]) {
            prime[++cnt] = i;
            for (int j = i * i; j * j <= r; j += i) ok[i] = 0;
        }
    }
}
/*
因为两者的差较小，所以先算出根号里的质数，然后分组筛
*/
void make() {
    for (register int i = 1; i <= cnt; i++) {
        int bei = l / prime[i];
        for (register int j = bei * prime[i]; j <= r; j += prime[i])
            if (j != prime[i] && j - l + 1 <= 1000001 && j - l + 1 >= 0)  // RE,注意可能的越界
                a[j - l + 1] = 0;
    }
    if (l == 1)
        a[1] = 0;
}
void search() {
    int pre = 0, mn = 0x3f3f3f3f3f, mx = 0, x, y, xx, yy;
    for (register int i = 1; i <= r - l + 1; i++) {
        if (a[i]) {
            if (pre) {
                if (i - pre > mx)
                    mx = i - pre, x = pre, y = i;
                if (i - pre < mn)
                    mn = i - pre, xx = pre, yy = i;
            }
            pre = i;
        }
    }
    if (mx && mn != 0x3f3f3f3f3f)
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n", xx + l - 1, yy + l - 1, x + l - 1,
               y + l - 1);
    else
        printf("There are no adjacent primes.\n");
}
signed main() {
    while (scanf("%lld%lld", &l, &r) != EOF) {
        memset(ok, 1, sizeof ok);
        ok[0] = ok[1] = 0;
        memset(a, 1, sizeof a);
        shai();
        make();
        search();
    }
}