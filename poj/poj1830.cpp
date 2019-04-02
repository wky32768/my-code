/*把对开关的影响转化成线性异或方程组，然后高斯消元
第0位是最后的常数，1~n位是1~n列的系数*/
#include <bits/stdc++.h>
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int n, t, ans, x, y, a[120];
signed main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        For(i, 1, n) scanf("%d", &a[i]);
        For(i, 1, n) {
            scanf("%d", &x);
            a[i] ^= x;
            a[i] |= (1 << i);
        }
        while (scanf("%d%d", &x, &y) && x && y) {
            a[y] ^= (1 << x);
        }
        ans = 1;//全部做完说明有唯一解
        For(i, 1, n) {
            For(j, i + 1, n) if (a[i] < a[j]) swap(a[i], a[j]);
            if (!a[i]) {
                ans = (1 << (n - i + 1));
                break;
            }//剩下的都是任意解
            if (a[i] == 1) {
                ans = 0;
                break;
            }//无解
            for (int k = n; k >= 1; k--)
                if ((a[i] >> k) & 1) {
					For(j,i+1,n) 
						if((a[j]>>k) & 1) a[j]^=a[i];
					break;//只对最高位进行操作
                }
        }
		if(!ans) puts("Oh,it's impossible~!!");
		else printf("%d\n",ans);
    }
	return 0;
}