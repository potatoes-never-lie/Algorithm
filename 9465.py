T = int(input())

for _ in range(T):
    n = int(input())
    array=[]
    for _ in range(2):
        array.append(list(map(int, input().split())))
    dp=[[0]*n for _ in range(2)]
    
    dp[0][0], dp[1][0]=array[0][0], array[1][0]

    if n>=2:
        dp[0][1], dp[1][1]=dp[1][0]+array[0][1], dp[0][0]+array[1][1]

    for i in range(2,n):
        for j in range(0,2):
            if j==0:
                dp[j][i]=max(dp[1][i-1], max(dp[0][i-2], dp[1][i-2]))+array[j][i]
            elif j==1:
                dp[j][i]=max(dp[0][i-1], max(dp[0][i-2], dp[1][i-2]))+array[j][i]

    print(max(dp[0][n-1], dp[1][n-1]))
