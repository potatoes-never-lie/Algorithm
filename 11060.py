from collections import deque

N=int(input())
graph=list(map(int, input().split()))
visited=[0]*N

def bfs():
    queue=deque()
    queue.append(0)
    while queue:
        x=queue.popleft()
        for i in range(1,graph[x]+1):
            nx=x+i
            if 0<=nx<N and visited[nx]==0:
                visited[nx]=visited[x]+1
                queue.append(nx)
if N==1:
    print(0)
else:
    bfs()
    if visited[N-1]==0:
        print(-1)
    else:
        print(visited[N-1])