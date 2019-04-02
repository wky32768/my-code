/*
破环为链，并用单调队列维护，使其变成O(n)的
关于单调队列：https://baijiahao.baidu.com/s?id=1606595798506539443&wfr=spider&for=pc
*/
#include <bits/stdc++.h>
using namespace std;
int n,ans,a[2200000];
deque <int> q;
signed main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        a[n+i]=a[i];
    }
    for(int i=1;i<=n*2;i++) {
        while(!q.empty() && i-q.front()>(n/2)) q.pop_front();
        if(!q.empty()) ans=max(ans,a[i]+a[q.front()]+i-q.front());
        while(!q.empty() && a[i]-i>a[q.back()]-q.back()) q.pop_back();
        q.push_back(i); 
    }
    printf("%d",ans);
    return 0;
}
