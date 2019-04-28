/*
CH里面的做法麻烦了，可以直接贪心
对于一个入度为0的点x，由于x无法被控制，所以只能不选。那么选择x控制的节点a[x]投放一定是最优的。 那么在选择a[x]之后，a[a[x]]就不能被a[x]限制了，那么把他的度数-1，如果a[a[x]]的度数=0，那么说明他也可以去限制别人了，就把他加入待转移集合中。我们可以用一个队列来实现这个操作。
但是以上的转移完成之后，以上的贪心方法类似于拓扑，所以不适用与环，那么环上的点是不会被加入集合的！但是我们发现对于一个长度为cnt的环，可以选择投放的点为cnt/2个（隔一个选一个嘛），那么我们就可以求出每一颗内向树环的长度即可
*/
#include <bits/stdc++.h>
using namespace std;
int n,a[1200000],du[1200000],ans;
bool vis[1200000];
queue <int> q;
signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        du[a[i]]++;
    }
    for(int i=1;i<=n;i++) if(!du[i]) q.push(i);
    
	while(!q.empty()) {
        int now=q.front();
        q.pop();
        if(!vis[now] && !vis[a[now]]) {
            ans++;
            vis[a[now]]=1;
            du[a[a[now]]]--;
            if(!du[a[a[now]]]) q.push(a[a[now]]);//跨两位纳入队列
        }
        vis[now]=1;
    }
    int tot,at;
    for(int i=1;i<=n;i++) if(!vis[i]) {
        tot=0;
        at=i;
        while(a[at]!=i) {
            vis[at]=1;
            tot++;
            at=a[at];
        }
        vis[at]=1;
        ans+=(tot+1)/2;//这里还有第一个(at)，所以要加一，不是上取整
    }
    cout<<ans;
    return 0;
}
