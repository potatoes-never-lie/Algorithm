d=[]
with open('a.txt','r') as f:
    n=int(f.readline())
    for i in range(n):
        f.readline()
        l=[int(i) for i in f.readline().split()]
        d.append(sorted(l))

for i in range(n):
    if len(d[i])==1:
        print("#"+str(i+1)+" "+str(d[i][0]))
    else:
        l=[]
        l.append(d[i].pop(0))
        l.append(d[i].pop(0))
        time=l[1]
        while len(d[i])!=0:
            l.sort()
            r=l.pop(0)
            time+=r
            d[i].append(r)
            d[i].sort()
            time+=d[i][-1]
            l.append(d[i].pop())
            l.append(d[i].pop())
        print("#"+str(i+1)+" "+str(time))