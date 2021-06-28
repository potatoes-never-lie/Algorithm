N = int(input())
array=list(map(int, input().split()))
d=[0]*N
d[0]=array[0]
for i in range(1,N):
    d[i]=max(d[i-1]+array[i], array[i])
    
print(max(d))