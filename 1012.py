import sys
sys.setrecursionlimit(10**6)
t = int(input())

def dfs(y,x):
    if x<0 or x>=m or y<0 or y>=n:
        return False
    if graph[y][x]==1: ##미방문 상태일 경우
        graph[y][x]=0
        dfs(y, x+1)
        dfs(y, x-1)
        dfs(y+1, x)
        dfs(y-1, x)
        return True
    return False


for _ in range(t):
    result=0
    m, n, k = map(int, input().split())
    graph = [[0]*m for _ in range(n)]
    for _ in range(k):
        x, y = map(int, input().split())
        graph[y][x] = 1
    for y in range(n):
        for x in range(m):
            if dfs(y,x)==True:
                result+=1
    print(result)
    
