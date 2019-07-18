#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int opt;
signed main() {
	cin>>opt;
	if(opt==1) {
		puts("I");
		puts("I");
		puts("+ 1 2");
		puts("< 3 1");
		puts("- 4");
		puts("O 5");
	} else if(opt==2) {
		puts("I");
		puts("< 1 4");
		puts("+ 2 1");
		puts("- 3");
		puts("S 4");	
		puts("O 5");
	} else if(opt==3) {
		puts("I");
		puts("< 1 100");
		puts("S 2");
		puts("< 3 1");
		puts("C 4 -1");
		puts("O 5");	
	} else if(opt==5) {
		For(i,1,32) puts("I");
		For(i,1,31) printf("< %d %d\n",i,32-i);//注意不要浪费 
		puts("+ 32 33");
		For(i,1,30) printf("+ %d %d\n",i+63,i+33);
		puts("O 94");
	}
}
