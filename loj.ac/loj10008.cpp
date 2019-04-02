#include <bits/stdc++.h>
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int m, n, tot = 0, at=1;
bool vis[1000100];
struct node {
    int date, money;
} a[1000100];
bool cmp(node x, node y) { return x.money > y.money; }
int read() {
    int x=0;
    char ch=getchar();
    while(!(ch>='0' && ch<='9')) ch=getchar();
    while(ch>='0' && ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
signed main() {
    cin >> n;
    For(i, 1, n) a[i].date=read(),a[i].money=read();
    sort(a + 1, a + n + 1, cmp);
    For(i, 1, n) {
        int flag = 0;
        for (register int j = a[i].date; j >= at; j--)
            if (!vis[j]) {
                flag = 1;
                vis[j] = 1;
                break;
            }
        if (flag) tot += a[i].money;
        while(vis[at]) at++;
    }
    cout << tot;
    return 0;
}