#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
class bigint {
	private:
		vector<int>a;
		int&operator[](int x) {
			if(size()<=x) {
				a.resize(x+1);
			}
			return a[x];
		}
		void mat() {
			for(unsigned i=0; i<a.size(); i++) {
				if(a[i]>9) {
					(*this)[i+1]+=a[i]/10;
					a[i]%=10;
				} else if(a[i]<0) {
					a[i+1]--;
					a[i]+=10;
				}
			}
			while(*a.rbegin()==0)a.pop_back();
		}
	public:
		int size() {
			return (int)(a.size());
		}
		bigint(int x) {
			a.clear();
			while(x>0) {
				a.push_back(x%10);
				x/=10;
			}
		}
		bigint(const bigint&x) {
			a=vector<int>(x.a);
		}
		bigint() {
			a.clear();
		}
		void print() {
			if(a.size()==0) {
				putchar('0');
				return;
			}
			for(int i=a.size()-1; i>=0; i--) {
				putchar(a[i]+'0');
			}
		}
		friend bigint operator+(bigint a,bigint b) {
			bigint ans(a);
			for(int i=0; i<b.size(); i++) {
				ans[i]+=b[i];
			}
			ans.mat();
			return ans;
		}
		friend bigint operator-(bigint a,bigint b) {
			bigint ans(a);
			for(int i=0; i<b.size(); i++) {
				ans[i]-=b[i];
			}
			ans.mat();
			return ans;
		}
		friend bigint operator*(bigint a,bigint b) {
			bigint ans(0);
			for(int i=0; i<a.size(); i++) {
				for(int j=0; j<b.size(); j++) {
					ans[i+j]+=a[i]*b[j];
				}
			}
			ans.mat();
			return ans;
		}
};
bigint ksm(bigint a,int n) {
	if(n==0)return bigint(1);
	if(n==1)return a;
	bigint ans=ksm(a,n/2);
	ans=ans*ans;
	if(n&1)ans=ans*a;
	return ans;
}
int n;
bigint C[120][120],f[120];
signed main() {
	C[0][0]=1;
	for(int i=1; i<=50; i++) {
		C[i][0]=1;
		for(int j=1; j<=i; j++) {
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	for(int i=1; i<=50; i++) {
		int yyh=(i-1)*i/2;
		bigint now=ksm(2,yyh);
		for(int k=1; k<i; k++) {
			now=now-C[i-1][k-1]*f[k]*ksm(2,(i-k)*(i-k-1)/2);
		}
		f[i]=now;
	}
	while(cin>>n) {
		if(n==0) break;
		f[n].print();
		puts("");
	}
	return 0;
}
