n,m,k=map(int, input().split())
maxVal=0

for i in range(0,k+1):
    team=min((n-i)//2, (m-(k-i))//1)
    maxVal=max(maxVal, team)

print(maxVal)