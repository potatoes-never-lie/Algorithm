n, m=map(int, input().split())
graph=[[] for _ in range(n+1)]
visited=[False]*(n+1)
result=0
for _ in range(m):
    i, j=map(int, input().split())
    graph[i].append(j)
    graph[j].append(i)

def dfs(v):
    visited[v]=True
    for x in graph[v]:
        if visited[x]==False:
            dfs(x)
        else:
            continue

for i in range(1,n+1):
    if visited[i]==False:
        dfs(i)
        result+=1

print(result)

##최대한 깊게깊게==dfs!!!이미 방문한곳은 방문하지않는다!이미
##깊게탐색햇을시에 탐색했기 때문.
##또 배열 전체를 넘겨줄필요는 없다!! 메모리만 낭비임. 다 기록된다.