from itertools import combinations
from collections import deque
import copy

N, M=map(int, input().split())
graph=[]
l=[]
candidates=[]
virus=[]
dx=[-1,1,0,0]
dy=[0,0,-1,1]
result=0

for i in range(N):
    graph.append(list(map(int, input().split())))
    for j in range(M):
        if graph[i][j]==0:
            l.append((i,j))
        elif graph[i][j]==2:
            virus.append((i,j))

candidates=list(combinations(l,3))
length=len(candidates)

def bfs(walls):
    count=0
    g=copy.deepcopy(graph)
    for x,y in walls:
        g[x][y]=1
    queue=deque(virus)
    while queue:
        x,y=queue.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if nx<0 or ny<0 or nx>=N or ny>=M:
                continue
            if g[nx][ny]==0:
                g[nx][ny]=2
                queue.append((nx,ny))
    for i in range(N):
        for j in range(M):
            if g[i][j]==0:
                count+=1
    return count  


for i in range(length):
    result=max(result,bfs(candidates[i]))

print(result)