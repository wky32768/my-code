#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {int w,last;} heap[120000],a[120000];
bool cmp(node a,node b) {return a.last<b.last;}
int n,cnt;
void up(int x) {
	while(x>1) {
		if(heap[x].w<heap[x/2].w) {
			swap(heap[x],heap[x/2]);
			x/=2;
		} else break;
	}
}
void insert(int x) {
	heap[++cnt]=a[x];
	up(cnt);
}
void down(int x) {
	int s=x*2;
	while(s<=cnt) {
		if(s<n && heap[s].w>heap[s+1].w) s++;
		if(heap[x].w>heap[s].w) {
			swap(heap[x],heap[s]);
			x=s;
			s=x*2;
		} else break;
	}
}
void del() {
	heap[1]=heap[cnt];
	cnt--;
	down(1);
}
signed main() {
	while(scanf("%lld",&n)==1) {
		for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].w,&a[i].last);
		sort(a+1,a+n+1,cmp);
		cnt=0;
		for(int i=1;i<=n;i++) {
			if(cnt>=a[i].last) {
				if(heap[1].w<a[i].w) {
					insert(i);
					del();
				}
			} else insert(i);
		}
		int tot=0;
		for(int i=1;i<=cnt;i++) tot+=heap[i].w;
		cout<<tot<<'\n';
	}
	return 0;

}
