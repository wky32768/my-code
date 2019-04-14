#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 120000;
int n, m, cnt, s, t, head[N], a[120000], b[120000], ans, now, depth[120000];
char ch[120000];
struct node {
	int next, to, w;
} sxd[N << 1];
void add(int u, int v, int w) {
	sxd[++cnt].next = head[u];
	sxd[cnt].to = v;
	sxd[cnt].w = w;
	head[u] = cnt;
}
queue<int> q;
bool bfs() {
	memset(depth, 0, sizeof depth);
	while (!q.empty())
		q.pop();
	q.push(s);
	depth[s] = 1;
	while (!q.empty()) {
		int at = q.front();
		q.pop();
		for (int i = head[at]; i!=-1; i = sxd[i].next)
			if (!depth[sxd[i].to] && sxd[i].w>0) {
				q.push(sxd[i].to);
				depth[sxd[i].to] = depth[at] + 1;
				if (sxd[i].to == t)
					return 1;
			}
	}
	return 0;
}
//int dfs(int x,int val) {
//    if(x==t) return val;
//    for(int i=head[x];i!=-1;i=sxd[i].next) {
//        if(sxd[i].w>0 && depth[sxd[i].to]==depth[x]+1) {
//            int carrot=dfs(sxd[i].to,min(val,sxd[i].w));
//            if(carrot>0) {
//                sxd[i].w-=carrot;
//                sxd[i^1].w+=carrot;
//                return carrot;
//            }
//        }
//    }
//    return 0;
//}
int dfs(int x,int val) {
	if(x==t) return val;
	int temp=val,k;
	for(int i=head[x]; i!=-1; i=sxd[i].next) {
		if(sxd[i].w>0 && temp && depth[sxd[i].to]==depth[x]+1) {
			k=dfs(sxd[i].to,min(val,sxd[i].w));
			if(!k) depth[sxd[i].to]=0;
			sxd[i].w-=k;
			sxd[i^1].w+=k;
			temp-=k;
		}
	}
	return val-temp;
}
signed main() {
//	freopen("f.in","r",stdin);
//	freopen("f.out","w",stdout);
	while (scanf("%lld%lld", &n, &m)!=EOF) {
		for (int i = 0; i < m; i++) {
			scanf("%s",ch);
			int j=0;
			for(a[i]=0,j=1; ch[j]!=','; j++) a[i]=a[i]*10+ch[j]-'0';
			for(b[i]=0,j++; ch[j]!=')'; j++) b[i]=b[i]*10+ch[j]-'0';
		}
		ans = 0x3f3f3f3f;
		for (t = 1; t < n; t++) {
			memset(head, -1, sizeof head);
			cnt = 1, now = 0;
			for (int i = 0; i < n; i++)
				if (i == t || i==s) {
					add(i, i + n, 0x3f3f3f3f);
					add(i+n,i,0);
				} else {
					add(i, i + n, 1);
					add(i+n,i,0);
				}
			for (int i = 0; i < m; i++) {
				add(a[i] + n, b[i], 0x3f3f3f3f);
				add(b[i],a[i]+n,0);
				add(b[i] + n, a[i], 0x3f3f3f3f);
				add(a[i],b[i]+n,0);
			}
			while (bfs()) {
				now += dfs(s, 0x3f3f3f3f);
			}
			ans = min(ans, now);
		}
		if (ans == 0x3f3f3f3f || n <= 1)
			ans = n;
		printf("%lld\n", ans);
	}
}
