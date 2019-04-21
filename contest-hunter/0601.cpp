//先用倍增一段一段处理，然后用归并排序优化复杂度
#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, m, k, paied, a[520000], b[520000],s[520000]; // b是排过序后的数组，s是辅助的数组
inline int read(){
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) {
		f|=(ch=='-');
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f?-x:x;
}
inline int pf(int x) { return x * x; }
inline void merge(int l, int mid, int r) { //归并排序
    int i = l, j = mid + 1;
    for (register int k = l; k <= r; k++) {
        if ((j > r) || (i <= mid && b[i] <= b[j])) {
            s[k] = b[i];
            i++;
        } else {
            s[k] = b[j];
            j++;
        }
    }
    return;
}
inline int make(int l, int r) {
    int t = min(m, (r - l + 1) >> 1);
    for (register int i = paied + 1; i <= r; i++)
        b[i] = a[i];
    sort(b + paied + 1, b + r + 1);
    merge(l, paied, r);
    int tot = 0;
    for (register int i = 1; i <= t; i++)
        tot += pf((s[r - (i - 1)] - s[l + (i - 1)]));
    return tot;
}
inline void solve() {
    int l = 1, r = 1, p = 0, ans = 0;
	paied=1;
	b[1]=a[1];
	/*
	Q:为什么paied要设成1?
	A:如果paied设成了0,在做merge的时候mid就小于l了,就会出锅.
	*/
    while (l <= n) {
        p = 1;
        while (p != 0) {
            int now = make(l, min(n, r + p));
            if (now <= k) {
                r = paied = min(n, r + p);
                for (register int i = l; i <= r; i++)
                    b[i] = s[i];
                if (r == n)
                    break;
                p <<= 1;
            } else
                p >>= 1;
        }
        ans++;
        l = r + 1;
    }
    printf("%lld",ans);
	puts("");
    return;
}
signed main() {
    scanf("%lld", &t);
    while (t--) {
       n=read(),m=read(),k=read();
        for (register int i = 1; i <= n; i++)
            a[i]=read();
        solve();
    }
    return 0;
}