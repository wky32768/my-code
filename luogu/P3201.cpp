//重点：熟练链表的使用方法(有点儿像边表)
#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
const int N = 1200000;
int n, m, cnt, ans, nxt[N], which[N], head[N], st[N], a[N], shu[N], opt, x, y;
/* 
nxt,head:维护链表
which：应该找那个颜色
st：队首
*/
void qifa(int x, int y) {
    for (int i = head[x]; i; i = nxt[i]) {
        if (a[i + 1] == y)
            ans--;
        if (a[i - 1] == y)
            ans--; //交界处合二为一以后答案会减少
    }
    for (int i = head[x]; i; i = nxt[i])
        a[i] = y;
    nxt[st[x]] = head[y];
    head[y] = head[x];   //链表交接
    head[x] = st[x] = 0; //清空
}
signed main() {
    cin >> n >> m;
    For(i, 1, n) {
        cin >> a[i];
        which[a[i]] = a[i];
        if (a[i] != a[i - 1])
            ans++;
        if (head[a[i]] == 0)
            st[a[i]] = i;
        shu[a[i]]++;
        nxt[i] = head[a[i]];
        head[a[i]] = i;
    }
    For(j, 1, m) {
        cin >> opt;
        if (opt == 2) {
            cout << ans << '\n';
        } else if (opt == 1) {
            cin >> x >> y;
            if (x == y)
                continue;

            if (shu[which[x]] > shu[which[y]]) {
                swap(which[x], which[y]);
            }
            x = which[x], y = which[y];
            if (shu[x] == 0)
                continue;

            /*
            x,y的顺序是确定的不能改变啊啊啊
            比如把1染成2，但是shu[1]>shu[2]，
            这时我们应该将2合并到1的链后面，
            但是会遇到一个麻烦的问题，
            就是这个链头是接1下的，也就是说以后找颜色2，发现没有颜色2只有颜色1。。。
            于是我们应该开一个数组which，表示我们寻找一种颜色时，实际应该找哪个颜色下的链，
            遇到上面那种情况要交换which[1]和which[2]
            */

            shu[y] += shu[x];
            shu[x] = 0;
            qifa(x, y);
            //不用更新which,因为真正有用的是head啊，前面说的顺序改变只是为了维持复杂度
        }
    }
}