from collections import deque

n,k=map(int, input().split())
MAX=10**5
dist=[0]*(MAX+1)

def bfs(n,k):
    queue=deque([n])
    if n==k:
        print(0)
    else:
        while queue:
            x=queue.popleft()
            if x-1==k or x+1==k or x*2==k:
                print(dist[x]+1)
                break
            for i in (x-1, x+1, x*2):
                if i>100000 or i<0 or dist[i]!=0: #이미 방문한것이나 범위를 벗어난것은 탐색하지않음
                    continue
                queue.append(i)     #처음 방문하는 경우에만 붙임
                dist[i]=dist[x]+1

bfs(n,k)