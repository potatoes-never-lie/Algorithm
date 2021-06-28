from collections import deque
import copy

n, m=map(int, input().split())
graph=[]
dx=[-1,1,0,0]
dy=[0,0,-1,1]
visited=[[False]*m for _ in range(n)]
year=0
for _ in range(n):
    graph.append(list(map(int, input().split())))

def bfs(i,j):
    visited[i][j]=True
    queue=deque()
    queue.append((i,j))
    while queue:
        x,y=queue.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<n and 0<=ny<m and graph[nx][ny]!=0 and visited[nx][ny]==False:
                visited[nx][ny]=True
                queue.append((nx,ny))

while True:
    year+=1
    count=0
    visited=[[False]*m for _ in range(n)]
    flag=0
    temp=copy.deepcopy(graph)
    for i in range(1,n-1):
        for j in range(1,m-1):
            if graph[i][j]!=0:
                for k in range(4):
                    ni=i+dx[k]
                    nj=j+dy[k]
                    if 0<=ni<n and 0<=nj<m and graph[ni][nj]==0:
                        if temp[i][j]>=1:
                            temp[i][j]-=1
    
    graph=copy.deepcopy(temp)
    for i in range(1,n-1):
        for j in range(1,m-1):
            if graph[i][j]!=0 and visited[i][j]==False:
                bfs(i,j)
                count+=1
    if count>=2:
        print(year)
        break
    for i in range(1,n-1):
        for j in range(1,m-1):
            if graph[i][j]!=0:
                flag=1
    if flag==0:
        print(0)
        break