//https://www.cnblogs.com/victorique/p/8480093.html
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1200000;
char ch[N];
int n, m = 122, tong[N], sa[N], x[N], y[N];
void suffix() {
    for (int i = 1; i <= n; i++) {
        x[i] = ch[i];
        tong[x[i]]++;
    }
    for (int i = 2; i <= m; i++) {
        tong[i] += tong[i - 1];
    }
    for (int i = n; i >= 1; i--)
        sa[tong[x[i]]--] = i; //基数排序
    for (int k = 1; k <= n; k <<= 1) {
        int num = 0;
        for (int i = n - k + 1; i <= n; i++)
            y[++num] = i;
        /*y[i]表示第二关键字排名为i的数，第一关键字的位置
        第n-k+1到第n位是没有第二关键字的 所以排名在最前面
        排名构成：后缀k的前两个字符，后缀k+2的前两个字符
        y默认了向后k个字符*/
        for (int i = 1; i <= n; i++)
            if (sa[i] > k)
                y[++num] = sa[i] - k;
        /*如果满足(sa[i]>k)
         * 那么它可以作为别人的第二关键字，就把它的第一关键字的位置添加进y就行了*/
        for (int i = 1; i <= m; i++)
            tong[i] = 0;
        for (int i = 1; i <= n; i++)
            tong[x[i]]++;
        for (int i = 2; i <= m; i++)
            tong[i] += tong[i - 1];
        for (int i = n; i >= 1; i--)
            sa[tong[x[y[i]]]--] = y[i], y[i] = 0; //记录&清空
        swap(x, y);                               /*把旧的转存*/
        x[sa[1]] = 1;
        num = 1;
        for (int i = 2; i <= n; i++)
            x[sa[i]] =
                (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k])
                    ? num
                    : ++num; //是否与上一个一样
        if (num == n)
            break; //排序已经完成
        m = num;
    }
    for (int i = 1; i <= n; i++)
        cout << sa[i] << " ";
}
signed main() {
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    suffix();
    return 0;
}