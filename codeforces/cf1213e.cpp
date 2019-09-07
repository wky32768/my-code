#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int n;
char ch[3][3];
signed main() {
    n=read();
    scanf("%s",ch[1]+1); scanf("%s",ch[2]+1);
    for(int i=0;i<=2;i++) for(int j=0;j<=2;j++) for(int k=0;k<=2;k++) if(i!=j && j!=k && k!=i) {
        if(i==(ch[1][1]-'a') && j==(ch[1][2]-'a')) continue;
        if(j==(ch[1][1]-'a') && k==(ch[1][2]-'a')) continue;
        if(k==(ch[1][1]-'a') && i==(ch[1][2]-'a') && n!=1) continue;
        if(i==(ch[2][1]-'a') && j==(ch[2][2]-'a')) continue;
        if(j==(ch[2][1]-'a') && k==(ch[2][2]-'a')) continue;
        if(k==(ch[2][1]-'a') && i==(ch[2][2]-'a') && n!=1) continue;
        puts("YES");
        For(a,1,n) cout<<char(i+'a')<<char(j+'a')<<char(k+'a');
        return 0;
    }
    if(ch[1][1]==ch[2][1] && ch[1][2]!=ch[2][2]) {
        puts("YES");
        For(a,1,n) cout<<ch[1][2];
        For(a,1,n) cout<<ch[2][2];
        For(a,1,n) cout<<ch[1][1];
        return 0;
    }
    if(ch[1][2]==ch[2][2] && ch[1][1]!=ch[2][1]) {
        puts("YES");
        For(a,1,n) cout<<ch[2][2];
        For(a,1,n) cout<<ch[1][1];
        For(a,1,n) cout<<ch[2][1];
        return 0;
    }
    if(ch[1][1]==ch[2][2] && ch[1][2]==ch[2][1]) {
        puts("YES");
        For(a,1,n) cout<<ch[1][1];
        For(a,1,n) cout<<char('a'+'b'+'c'-ch[1][1]-ch[2][1]);
        For(a,1,n) cout<<ch[1][2];
        return 0;
    }
    puts("NO");
    return 0;
}