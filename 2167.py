n, m=map(int, input().split())
arr=[]
result=[]
for i in range(n):
    arr.append(list(map(int, input().split())))
k=int(input())

for i in range(k):
    i,j,x,y=map(int, input().split())
    i,j,x,y=i-1,j-1,x-1,y-1
    res=sum(arr[i][j:])
    for a in range(i+1,x):
        res+=sum(arr[a])
    res+=sum(arr[x][:y+1])
    result.append(res)

for res in result:
    print(res)