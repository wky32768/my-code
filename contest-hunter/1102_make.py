fo = open("foo.txt", "w")
now=1
for i in range (1,60000):
    now=now*i
    fo.write("%d"%(now))
    fo.write('\n')
fo.close()