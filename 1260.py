from collections import deque

n, m, v=map(int, input().split())
edges=[]
graph=[[]]
visited=[False]*(n+1)
for _ in range(m):
    edges.append(tuple(map(int, input().split())))

for _ in range(n):
    graph.append([])

for edge in edges:
    graph[edge[0]].append(edge[1])
    graph[edge[1]].append(edge[0])

for i in range(1,n+1):
    graph[i].sort()

#dfs
def dfs(graph, v, visited):
    visited[v]=True
    print(v, end=' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

def bfs(graph, start, visited):
    queue=deque([start])
    visited[start]=True
    while queue:
        v=queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i]=True

dfs(graph, v, visited)
print("")
visited=[False]*(n+1)
bfs(graph, v, visited)


