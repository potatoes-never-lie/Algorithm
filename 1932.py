n=int(input())
tri=[]
dp=[]
for i in range(n):
    tri.append(list(map(int, input().split())))
    dp.append([0]*(i+1))

for i in range(n):
    dp[n-1][i]=tri[n-1][i]

for i in range(n-2,-1,-1):
    for j in range(0,i+1):
        dp[i][j]+=max(dp[i+1][j], dp[i+1][j+1])+tri[i][j]

print(dp[0][0])