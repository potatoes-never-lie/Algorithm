t=int(input())

dpZero=[0]*41
dpOne=[0]*41

dpZero[0]=1
dpOne[1]=1

for i in range(2,41):
    dpZero[i]=dpZero[i-1]+dpZero[i-2]
    dpOne[i]=dpOne[i-1]+dpOne[i-2]


for _ in range(t):
    i=int(input())
    print(str(dpZero[i])+" "+str(dpOne[i]))