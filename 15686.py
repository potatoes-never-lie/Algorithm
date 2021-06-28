from itertools import combinations

N, M=map(int, input().split())
graph=[]
houses=[]
chickens=[]
result2=int(1e9)
result1=int(1e9)

for i in range(N):
    graph.append(list(map(int, input().split())))
    for j in range(N):
        if graph[i][j]==1:
            houses.append((i,j))
        elif graph[i][j]==2:
            chickens.append((i,j))

for i in range(1,M+1):
    l=list(combinations(chickens,i))
    for c in l:
        totaldist=0
        for hx,hy in houses:
            mini=int(1e9)
            for cx, cy in c:
                mini=min(abs(hx-cx)+abs(hy-cy),mini)
            totaldist+=mini
        result2=min(result2, totaldist)
    result1=min(result1, result2)

print(result1)