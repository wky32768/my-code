#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[4][4],n,ans[1200][1200];
void make(int at,int stx,int sty) {
	if(at==1) {
		ans[stx][sty]=1;
		return;
	} else {
		make(at-1,stx,sty);
		make(at-1,stx,sty+pow(3,at-2)*2);	
		make(at-1,stx+pow(3,at-2),sty+pow(3,at-2)),
		make(at-1,stx+pow(3,at-2)*2,sty);
		make(at-1,stx+pow(3,at-2)*2,sty+pow(3,at-2)*2);
	}
}
signed main() {
	a[1][1]=a[1][3]=a[2][2]=a[3][1]=a[3][3]=1;
	while(cin>>n && n!=-1) {
		memset(ans,0,sizeof ans);
		make(n,1,1);
		for(int i=1; i<=pow(3,n-1); i++) {
			for(int j=1; j<=pow(3,n-1); j++)
				if(ans[i][j]) cout<<"X";
				else cout<<" ";
			puts("");
		}
		puts("-");
	}
}
