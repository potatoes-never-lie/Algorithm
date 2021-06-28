N, K=map(int, input().split())
coins=[]
count=0

for _ in range(N):
    coins.append(int(input()))

for i in range(N-1,-1,-1):
    count+=K//coins[i]
    K=K%coins[i]

print(count)