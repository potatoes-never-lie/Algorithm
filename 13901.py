r, c=map(int, input().split())
k=int(input())
hurdles=[]
visited=[[False]*c for _ in range(r)]
for _ in range(k):
    hurdles.append(tuple(map(int, input().split())))
sr, sc=map(int, input().split())
moves=list(map(int, input().split()))
visited[sr][sc]=True

dx=[0,-1,1,0,0]
dy=[0,0,0,-1,1]

while True:
    isMoved=False
    for move in moves:
        while True:
            sr+=dx[move]
            sc+=dy[move]
            if sr<0 or sc<0 or sr>=r or sc>=c or (sr, sc) in hurdles or visited[sr][sc]==True:
                sr-=dx[move]
                sc-=dy[move]
                break
            visited[sr][sc]=True
            isMoved=True
    if isMoved==False:
        print(str(sr)+" "+str(sc))
        break

