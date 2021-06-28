n=int(input())
array=[0]*(n+1)
dp=[0]*(n+1)
for i in range(1,n+1):
    array[i]=int(input())

for i in range(1,n+1):
    if i==1:
        dp[1]=array[1]
    elif i==2:
        dp[2]=array[1]+array[2]
    elif i==3:
        dp[3]=max(array[1]+array[3], array[2]+array[3])
    else:
        dp[i]=max(dp[i-3]+array[i-1]+array[i], dp[i-2]+array[i])

print(dp[n])