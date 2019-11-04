a,b,c=map(int,input().split())
if a*b//c+b*c//a+c*a//b>a+b+c:
    print("YES")
else:
    print("NO")
