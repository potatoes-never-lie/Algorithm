n=int(input())
arr=list(map(int, input().split()))
result=0
arr.sort()

for i in range(1,n+1):
    result+=arr[i-1]*(n+1-i)

print(result)