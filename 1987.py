r, c=map(int, input().split())
graph=[]
dx=[-1,1,0,0]
dy=[0,0,-1,1]
visited=[[False]*c for _ in range(r)]
alphabet=[False]*26
result=0

for _ in range(r):
    graph.append(input())

def dfs(x, y, count):
    global result
    visited[x][y]=True
    alphabet[ord(graph[x][y])-ord('A')]=True
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx<r and 0<=ny<c and visited[nx][ny]==False and alphabet[ord(graph[nx][ny])-ord('A')]==False:
            dfs(nx, ny, count+1)
            visited[nx][ny]=False
            alphabet[ord(graph[nx][ny])-ord('A')]=False
    result=max(result, count)
    return result

dfs(0,0,1)
print(result)