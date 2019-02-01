#include<bits/stdc++.h>
using namespace std;
inline int read() {
    char c=getchar();
    int x=0,f=1;
    while(c<'0'||c>'9') {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
int mx[1200000][21];
int query(int l,int r) {
    int k=log2(r-l+1);
    return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) mx[i][0]=read();
    for(int j=1; j<=21; j++)
        for(int i=1; i+(1<<j)-1<=n; i++)
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
    for(int i=1; i<=m; i++) {
        int l,r;
        l=read();
        r=read();
        cout<<query(l,r)<<'\n';
    }
    return 0;
}
