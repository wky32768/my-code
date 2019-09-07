#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,v=1,x=0,a[12000],b[12000];
double dis,ans;
char ch;
signed main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>ch>>x;
		if(ch=='T') a[++a[0]]=x;
		else b[++b[0]]=x;
	}
	sort(a+1,a+a[0]+1);
	sort(b+1,b+b[0]+1);
	int at1=1,at2=1;
	double t=0;
	for(int i=1;(at1!=a[0]+1 || at2!=b[0]+1); i++) {
		double dis1=0x3f3f3f3f,dis2=0x3f3f3f3f;
		if(at1!=a[0]+1) dis1=dis+(a[at1]*1.0-t)/v;
		if(at2!=b[0]+1) dis2=b[at2];
		if(dis1!=dis2) {
			if(dis1<dis2 && dis1<10000) {
				dis=dis1;
				t=a[at1];
				v++;
				at1++;
			} else if(dis2<dis1 && dis2<10000) {
				t+=(b[at2]-dis)*v;
				dis=dis2;
				v++;
				at2++;
			}
		} else {
			dis=dis2;
			t=a[at1];
			v+=2;
			at1++,at2++;
		}
	}
	t+=(1000-dis)*v;
	cout<<(int)(t+0.5);
	return 0;
}
