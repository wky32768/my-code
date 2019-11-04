#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int n,now[4][4]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
inline int find(int x,int y) {
	return (x/4)*(n/4)+y/4+1;
}//µÚ¼¸¸ö¿é 
signed main() {
    n=read();
    For(i,0,n-1) {
        For(j,0,n-1) {
            int at=find(i,j);
            cout<<(at-1)*16+now[i%4][j%4]<<" ";
        }
        puts("");
    }
    return 0;
}
