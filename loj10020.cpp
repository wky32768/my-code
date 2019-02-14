#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int n,a[1200],mx,mn=0x3f3f3f3f,cnt,x,tot;
void dfs(int left,int now,int length,int at) {
	if(!left) {
		cout<<length;
		exit(0);
	}
	if(now==length) dfs(left-1,0,length,120);
	else for(register int i=at;i>=mn;i--) if(a[i] && i+now<=length) {
			a[i]--;
			dfs(left,now+i,length,i);
			a[i]++;
			if(now==0 || now+i==length) break;
		}
	return;
}
signed main() {
	cin>>n;
	while(n--) {
		cin>>x;
		if(x>50) continue;
		cnt++;
		a[x]++;
		tot+=x;
		mx=max(mx,x);
		mn=min(mn,x);
	}
	n=cnt;
	For(i,mx,tot) if(tot%i==0) dfs(tot/i,0,i,mx);
	return 0;
}