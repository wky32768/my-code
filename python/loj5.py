for x in range(1,20021231):
    if ((x ** x % 911) + (x ^ (x % 1248679)) == 20000000):
        print(x)
    
