n=int(input())
a,b=map(int, input().split())
graph=[[] for _ in range(n+1)]
visited=[False]*(n+1)
m=int(input())
result=-1
for _ in range(m):
    i,j=map(int, input().split())
    graph[i].append(j)
    graph[j].append(i)

def dfs(a, b, count):
    global result
    if a==b:
        result=count
    visited[a]=True
    for i in graph[a]:
        if visited[i]==False:
            dfs(i,b,count+1)
    return result

print(dfs(a,b,0))