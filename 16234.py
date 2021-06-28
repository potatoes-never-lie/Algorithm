from collections import deque

n, l, r=map(int, input().split())
graph=[]
visited=[[False]*n for _ in range(n)]
dx=[-1,1,0,0]
dy=[0,0,-1,1]
count=0
for _ in range(n):
    graph.append(list(map(int, input().split())))

def bfs(i, j):
    union=[]
    total=0
    if visited[i][j]==True:
        return
    queue=deque([(i,j)])
    union.append((i,j))
    visited[i][j]=True
    while queue:
        x,y=queue.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<n and 0<=ny<n and visited[nx][ny]==False:
                if l<=abs(graph[nx][ny]-graph[x][y])<=r:
                    visited[nx][ny]=True
                    queue.append((nx,ny))
                    union.append((nx,ny))
    if len(union)==1:
        return False
    #print(union)
    for i,j in union:
        total+=graph[i][j]
    p=total//len(union)
    for i,j in union:
        graph[i][j]=p
    return True

while True:
    isChanged=False
    visited=[[False]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if bfs(i,j)==True:      
                isChanged=True
    if isChanged==False:
        break
    count+=1

print(count)