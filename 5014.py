from collections import deque

F, S, G, U, D=map(int, input().split())
dist=[0]*(F+1)

def bfs():
    if S==G:
        return 0
    else:
        queue=deque([S])
        dist[S]=1
        while queue:
            x=queue.popleft()
            if x+U==G or x-D==G:
                return dist[x] 
            for i in (x+U, x-D):
                if i<=0 or i>F or dist[i]!=0:
                    continue
                dist[i]=dist[x]+1
                queue.append(i)
    return "use the stairs"

print(bfs())
