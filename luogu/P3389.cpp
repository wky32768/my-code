#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=120;
double a[N][N];
int n;
signed main() {
    cin>>n;
    For(i,1,n) For(j,1,n+1) cin>>a[i][j];
    For(i,1,n) {
        double now=a[i][i];
        if(abs(now)<1e-8) return puts("No Solution"),0;
        For(j,1,n) if(j!=i){
            double times=a[j][i]/now;
            For(k,1,n+1) a[j][k]-=a[i][k]*times;
        }
        For(j,1,n+1) a[i][j]/=now;
    }
    For(i,1,n) printf("%.2f\n",a[i][n+1]);
    return 0;
}