from collections import deque

m, n, h=map(int, input().split())
graph=[]
t=[]
for i in range(h):
    l=[]
    for j in range(n):
        l.append(list(map(int, input().split())))
    graph.append(l)

dx=[-1,1,0,0,0,0]
dy=[0,0,-1,1,0,0]
dz=[0,0,0,0,-1,1]

def bfs(t):
    queue=deque(t)
    while queue:
        z,x,y=queue.popleft()
        for i in range(6):
            nx=x+dx[i]
            ny=y+dy[i]
            nz=z+dz[i]
            if nx<0 or nx>=n or ny<0 or ny>=m or nz<0 or nz>=h:
                continue
            if graph[nz][nx][ny]==-1:
                continue
            if graph[nz][nx][ny]==0:
                graph[nz][nx][ny]=graph[z][x][y]+1
                queue.append((nz,nx,ny))

isNotRiped=False
for i in range(h):
    for j in range(n):
        for k in range(m):
            if graph[i][j][k]==0:
                isNotRiped=True
            if graph[i][j][k]==1:
                t.append((i,j,k))
            
if isNotRiped:
    bfs(t)
    flag=0
    result=0
    for i in range(h):
        for j in range(n):
            for k in range(m):
                result=max(result,graph[i][j][k])
                if graph[i][j][k]==0:
                    flag=1
    if flag==1:
        print(-1)
    else:
        print(result-1)
else:
    print(0)
