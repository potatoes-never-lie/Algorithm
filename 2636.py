from collections import deque

N, M=map(int, input().split())
graph=[]
cheeses=[]
dx=[-1,1,0,0]
dy=[0,0,-1,1]
count=0

for i in range(N):
    graph.append(list(map(int, input().split())))
    for j in range(M):
        if graph[i][j]==0:
            graph[i][j]=1
            cheeses.append((i,j))
        else:
            graph[i][j]=0

def bfs():
    queue=deque(cheeses)
    while queue:
        x,y=queue.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<N and 0<=ny<M and graph[nx][ny]==0:
                graph[nx][ny]=graph[x][y]+1
                queue.append((nx,ny))

bfs()
result=max(map(max,graph))
print(result-1)
print(graph)
for i in range(N):
    for j in range(M):
        if graph[i][j]==result:
            count+=1
print(count)

