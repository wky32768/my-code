#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=23;
int n,cant[N],use[N],tel[N],shu;
char ch[N];
inline bool imp() {
	For(i,1,9) {
		int tot=0;
		For(j,1,n) if(cant[j]==i) tot++;
		if(n-tot<use[i]) return 1;	
	}
	return 0;
}
inline void baoli() {
	int ans,mn=0x3f3f3f3f;
	sort(tel+1,tel+n+1);
	do {
		bool flag=1;
		For(i,1,n) if(tel[i]==cant[i]) {flag=0;break;}
		if(flag==0) continue;
		int num=0;
		For(i,1,n) num=num*10+tel[i];
		if(abs(shu-num)<mn) {
			mn=abs(shu-num);
			ans=num;	
		}
	}while(next_permutation(tel+1,tel+n+1));
	cout<<ans;
}
int buxing[N],mn=0,mx=0,dianhua[N];
int ans[N],ans_use[N];
inline bool keyi(int st) {
	int aa[12],bb[12];
	memset(aa,0,sizeof aa);
	memset(bb,0,sizeof bb);
	For(i,st,n) aa[cant[i]]++;
	For(i,1,9) bb[i]=dianhua[i]-ans_use[i];
	For(i,1,9) if(aa[i]+bb[i]>n-st+1) return 0;	
	return 1;
}
inline void trial() {
	For(i,1,n) buxing[cant[i]]++;
	For(i,1,n) dianhua[tel[i]]++;
	bool flag1=1,flag2=1;
	//第一轮：必须比他小 
	int peng=1;
	For(i,1,n) {
		int real=0;
		For(j,1,9) if(j!=cant[i] && dianhua[j]>=ans_use[j]+1) {
			ans[i]=j;
			ans_use[j]++;
			if(keyi(i+1)) {
				if(peng==1) {
					if(j<=tel[i]) real=j;	
				} else {
					real=j;					
				}
			}
			ans_use[j]--;
			ans[i]=j;
		}
		if(real==0) {flag1=0;break;}
		ans[i]=real;
		ans_use[real]++;
		if(real!=tel[i]) peng=0;
	}
	int ans1=0;
	For(i,1,n) ans1=ans1*10+ans[i];
	memset(ans,0,sizeof ans);
	memset(ans_use,0,sizeof ans_use);
	peng=1;
	//第二轮：要比他大 
	For(i,1,n) {
		int real=0x3f3f3f3f;
		For(j,1,9) if(j!=cant[i] && dianhua[j]>=ans_use[j]+1) {
			ans[i]=j;
			ans_use[j]++;
			if(keyi(i+1)) {
				if(peng==1) {
					if(j>=tel[i]) real=min(real,j);
				} else {
					real=min(real,j);
				}
			}
			ans_use[j]--;
			ans[i]=j;
		}
		if(real==0x3f3f3f3f) {flag2=0;break;}
		ans[i]=real;
		ans_use[real]++;
		if(real!=tel[i]) peng=0;
	}
	int ans2=0;
	For(i,1,n) ans2=ans2*10+ans[i];
	if(flag1==0) cout<<ans2;
	else if(flag2==0) cout<<ans1;
	else if(abs(shu-ans1)==abs(ans2-shu)) cout<<ans1;
	else if(abs(shu-ans1)<abs(ans2-shu)) cout<<ans1;
	else cout<<ans2; 
}
signed main() {
	n=read();
	scanf("%s",ch+1);
	For(i,1,n) cant[i]=read();
	For(i,1,n) use[ch[i]-'0']++;
	if(imp()==1) return puts("-1"),0;
	For(i,1,n) tel[i]=ch[i]-'0',shu=shu*10+tel[i];
	trial();
}

