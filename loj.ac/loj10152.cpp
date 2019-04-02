#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=(int)a;i<=(int)b;i++)
using namespace std;
struct big {
	static const int BASE=1e8;
	static const int width=8;
	vector <int> s;
	big() {
		*this=0;
	}
	big(const int &num) {
		*this=num;
	} 
	big operator =(int num) {
		s.clear();
		while(num>0) {
			s.push_back(num%BASE);
			num/=BASE;
		}
		return *this;
	}
	big operator =(const string &str) {
		s.clear();
		int x,len=(str.length()-1)/width+1;
		For(i,0,len-1) {
			int end=str.length()-i*width;
			int start=max(0ll,end-width);
			sscanf(str.substr(start,end-start).c_str(),"%lld",&x);
			s.push_back(x);
		}
		return *this;
	}
	friend istream & operator >> (istream &input,big &x) {
		string s;
		if(!(input>>s)) return input;
		x=s;
		return input;
	}
	friend ostream & operator << (ostream &output,const big &x) {
		if(x.s.empty())exit(0);
		output<<x.s.back();
		for(int i=x.s.size()-2; i>=0; i--) {
			char ch[25];
			sprintf(ch,"%08lld",x.s[i]);
			For(j,0,strlen(ch)-1) output<<ch[j];
		}
		return output;
	}

	friend bool operator < (const big &a,const big &b) {
		if(a.s.size()!=b.s.size()) return a.s.size()<b.s.size();
		for(int i=a.s.size()-1; i>=0; i--) if(a.s[i]!=b.s[i]) return a.s[i]<b.s[i];
		return 0;
	}
	bool operator >= (const big &b) {
		return !(*this<b);
	}
	friend big operator == (const big &a,const big &b) {
		if(a.s.size()!=b.s.size()) return 0;
		For(i,0,a.s.size()-1) if(a.s[i]!=b.s[i]) return 0;
		return 1;
	}
	friend big operator + (const big &a,const big &b) {
		big c;
		c.s.clear();
		for(int i=0,g=0;; i++) {
			if(g==0 && i>=(int)a.s.size() && i>=(int)b.s.size()) break;
			int x=g;
			if(i<(int)a.s.size()) x+=a.s[i];
			if(i<(int)b.s.size()) x+=b.s[i];
			c.s.push_back(x%BASE);
			g=x/BASE;
		}
		return c;
	}
	friend big operator - (const big &a,const big &b) {
		big c;
		c=a;
		For(i,0,c.s.size()-1) {
			int now=(i>=(int)b.s.size()?0:b.s[i]);
			if(now>c.s[i]) {
				c.s[i+1]--;
				c.s[i]+=BASE;
			}
			c.s[i]-=now;
		}
		while(c.s.back()==0 && c.s.size()>1) c.s.pop_back();
		return c;
	}
	void operator -= (const big &b) {
		*this=*this-b;
	}
	friend big operator * (const big &a,const big &b) {
		big c;
		c.s.resize(a.s.size()+b.s.size());
		For(i,0,a.s.size()-1) For(j,0,b.s.size()-1) c.s[i+j]+=a.s[i]*b.s[j];
		For(i,0,c.s.size()-2) {
			c.s[i+1]+=c.s[i]/BASE;
			c.s[i]%=BASE;
		}
		while(c.s.back()==0 && c.s.size()>1) c.s.pop_back();
		return c;
	}
};
big copy(const big &a,int x) {
	big b;
	b.s.resize(a.s.size()+x);
	For(i,0,a.s.size()-1) b.s[i+x]=a.s[i];
	return b;
}
big divide(const big &a,const big &b,big &mod) {
	big c;
	c.s.resize(a.s.size()-b.s.size()+1);
	mod=a;
	int Pow[(int)log2(big::BASE)+5];
	Pow[0]=1;
	For(i,1,log2(big::BASE)) Pow[i]=Pow[i-1]*2;
	for(int i=c.s.size()-1; i>=0; i--) {
		big t=copy(b,i);
		for(int j=log2(big::BASE); j>=0; j--) if(mod>=t*Pow[j]) {
				c.s[i]+=Pow[j];
				mod-=t*Pow[j];
			}
	}
	while(c.s.back()==0 && c.s.size()>1) c.s.pop_back();
	return c;
}
int n,m;
big a[120],f[120][120],ans;
signed main() {
	cin>>n>>m;
	For(i,1,n) {
		For(j,1,m) cin>>a[j];
		For(j,1,m) f[j][j]=a[j];
		For(len,1,m-1) For(l,1,m-len) {
			int r=len+l;
			f[l][r]=max(a[l]+2*f[l+1][r],a[r]+2*f[l][r-1]);

		}
		ans=ans+f[1][m]*2;
	}
	cout<<ans;
	return 0;
}
