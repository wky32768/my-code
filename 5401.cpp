#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,head[120000],f[120000][5],w[120000];
struct node {
    int next,to;
} sxd[120000];
void add(int u,int v) {
    sxd[++cnt].next=head[u];
    sxd[cnt].to=v;
    head[u]=cnt;
}
signed main() {



}