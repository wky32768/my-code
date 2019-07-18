#include <bits/stdc++.h>
#define int long long
using namespace std;
char a[1200],b[1200];
int n,ans;
map <int,int> mp[230000];
signed main() {
    cin>>n;
    while(n--) {
        cin>>a>>b;
        int x=a[0]*26+a[1],y=b[0]*26+b[1];
        ans+=mp[y][x];
        if(x==y) ans-=mp[y][x];
        mp[x][y]++;
    }
    cout<<ans;
    return 0;
}