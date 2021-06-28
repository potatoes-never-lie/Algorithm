N=int(input())
A=list(map(int, input().split()))
dp=[0]*N
dp[0]=1

for i in range(1,N):
    max_value=0
    for j in range(0,i):
        if A[i]>A[j]:
            max_value=max(dp[j], max_value)
    dp[i]=max_value+1

print(max(dp))