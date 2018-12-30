#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int a[1200000],n,x,y,siz;
bool cmp(int a,int b) {return a>b;}
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>x;
		if(x==1) {
			cin>>y;
			a[++siz]=y;
			make_heap(a+1,a+siz+1,cmp);
		} else if(x==2) {
			cout<<a[1]<<'\n';
		} else if(x==3) {
			pop_heap(a+1,a+siz+1,cmp);
			siz--;
		}
	}
}

