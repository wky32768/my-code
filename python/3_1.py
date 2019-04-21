import random
ans=random.randint(1,100)
get=input("请猜一个数字吧(1-100):")
num=int(get)
while num!=ans:
    if num>ans:
        print("too big!")
        num=int(input())
    elif num<ans:
        print("too small!")
        num=int(input())
print("牛逼啊！")
