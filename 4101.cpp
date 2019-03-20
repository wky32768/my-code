/*
dis[x]:x到树根路径上所有点的边权和
sz[x]:x这一列有几艘战舰
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 520000;
int n, x, y, xx, yy, fa[N], dis[N], sz[N];
char ch;
int get(int x) {
    if (fa[x] == x)
        return x;
    int root = get(fa[x]);
    dis[x] += dis[fa[x]]; //递归找到队头后更新距离(只会增加最新连接的边，不然对头的dis就会为0)
    return fa[x] = root;
}
void merge(int x, int y) {
    fa[x] = y;
    dis[x] += sz[y];
    sz[y] += sz[x];
}
signed main() {
    scanf("%lld", &n);
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    while (n--) {
        cin>>ch>>x>>y;
        xx = get(x), yy = get(y);
        if(ch=='M') merge(xx,yy);
        else {
            if(xx!=yy) puts("-1");
            else printf("%lld\n",abs(dis[y]-dis[x])-1);
        }
    }
    return 0;
}
