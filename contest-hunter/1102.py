now=1
n=int(input())
for i in range(n+1,2*n+1):
    now=now*i
for i in range(1,n+1):
    now=now//i
now=now//(n+1)
print(now)