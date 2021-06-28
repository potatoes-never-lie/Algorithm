from collections import deque

N, M=map(int, input().split())
graph=[set() for _ in range(N+1)]
visited=[False]*(N+1)
result=0
array=[]

for _ in range(M):
    a,b=map(int, input().split())
    graph[a].add(b)
    graph[b].add(a)

def bfs(i):
    result=0
    queue=deque()
    queue.append((i,0))
    visited[i]=True
    while queue:
        pos, cnt=queue.popleft()
        result+=cnt
        for i in graph[pos]:
            if not visited[i]:
                queue.append((i,cnt+1))
                visited[i]=True
    return result

for i in range(1,N+1):
    visited=[False]*(N+1)
    array.append(bfs(i))

print(array.index(min(array))+1)