N=int(input())
A=list(map(int, input().split()))
dp=[0]*N

for i in range(N):
    dp[i]=A[i]
    max_value=0
    for j in range(0,i):
        if A[i]>A[j]:
            max_value=max(max_value, dp[j])
    dp[i]+=max_value

print(max(dp))