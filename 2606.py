n=int(input())
m=int(input())
edges=[]
graph=[[]]
visited=[False]*(n+1)
count=0
for _ in range(m):
    edges.append(tuple(map(int, input().split())))

for _ in range(n):
    graph.append([])

for edge in edges:
    graph[edge[0]].append(edge[1])
    graph[edge[1]].append(edge[0])

for i in range(1,n+1):
    graph[i].sort()

def dfs(graph, v, visited):
    visited[v]=True
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

dfs(graph, 1, visited)
for isvisited in visited[2:]:
    if isvisited:
        count+=1

print(count)