from collections import deque

N, M=map(int, input().split())
graph=[]
dist=[[[0,0] for _ in range(M)] for _ in range(N)]
dx=[-1,1,0,0]
dy=[0,0,-1,1]
for i in range(N):
    graph.append(list(map(int, input())))

def bfs(x,y,flag):
    queue=deque()
    queue.append((x,y,flag))
    dist[x][y][flag]=1
    while queue:
        x,y,flag=queue.popleft()
        if x==N-1 and y==M-1:
            return dist[N-1][M-1][flag]
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if nx<0 or nx>=N or ny<0 or ny>=M:
                continue
            if dist[nx][ny][flag]!=0:
                continue
            if graph[nx][ny]==0:
                dist[nx][ny][flag]=dist[x][y][flag]+1
                queue.append((nx,ny,flag))
            if graph[nx][ny]==1 and flag==0:
                dist[nx][ny][1]=dist[x][y][flag]+1
                queue.append((nx,ny,1))
    return -1

print(bfs(0,0,0))
