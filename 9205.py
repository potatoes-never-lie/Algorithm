from collections import deque

t=int(input())
INF=int(1e9)

for _ in range(t):
    flag=0
    n=int(input())
    graph=[[INF]*(n+3) for _ in range(n+3)]
    array=[[] for _ in range(n+3)]
    visited=[False]*(n+3)
    l=[()]
    for a in range(1,n+3):
        for b in range(1, n+3):
            if a==b:
                graph[a][b]=0
    for _ in range(n+2):
        x,y=map(int, input().split())
        l.append((x,y))
    for i in range(1,n+3):
        for j in range(i, n+3):
            dist=abs(l[i][0]-l[j][0])+abs(l[i][1]-l[j][1])
            graph[i][j]=dist
            graph[j][i]=dist
    
    for k in range(1, n+3):
        for a in range(1, n+3):
            for b in range(1, n+3):
                graph[a][b]=min(graph[a][b], graph[a][k]+graph[k][b])
    
    for a in range(1,n+3):
        for b in range(1, n+3):
            if 0<graph[a][b]<=1000:
                array[a].append(b)

    queue=deque([1])
    visited[1]=True
    while queue:
        v=queue.popleft()
        for i in array[v]:
            if not visited[i]:
                queue.append(i)
                visited[i]=True

    if visited[n+2]==True:
        print("happy")
    else:
        print("sad")
