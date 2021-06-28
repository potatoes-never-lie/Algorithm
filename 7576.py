from collections import deque

m, n=map(int, input().split())
graph=[]
ones=[]
flag=0
for i in range(n):
    graph.append(list(map(int, input().split())))

for i in range(n):
    for j in range(m):
        if graph[i][j]==1:
            ones.append((i,j))

dy=[-1,1,0,0]
dx=[0,0,-1,1]

def bfs():
    queue=deque(ones)
    while queue:
        x,y=queue.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if nx<0 or ny<0 or nx>=n or ny>=m:
                continue
            if graph[nx][ny]==-1:
                continue
            if graph[nx][ny]==0:
                graph[nx][ny]=graph[x][y]+1
                queue.append((nx,ny))

bfs()
for i in range(n):
    for j in range(m):
        if graph[i][j]==0:
            flag=1
if flag==1:
    print(-1)
else:
    print(max(map(max,graph))-1)


##pypy3 로 제출하는게 빠르다.. 그리고 무작정 어렵게 생각했는데 그렇게 하지 말고
##기존 bfs 방식과 유사하다는 점!!1인것들 넣고, 인접한것들 더해서 2인것들 넣고.. 하는식으로 인접은 얼모스트 비피에스.