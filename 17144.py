R, C, T=map(int, input().split())
room=[]
purifier=[]
dx=[0,0,-1,1]
dy=[-1,1,0,0]
sum=0
for i in range(R):
    room.append(list(map(int, input().split())))

def cleaner():
    up=purifier[0]
    down=purifier[1]
    for y in range(up-1,0,-1):
        room[y][0]=room[y-1][0]
    for x in range(0,C-1,1):
        room[0][x]=room[0][x+1]
    for y in range(0,up,1):
        room[y][C-1]=room[y+1][C-1]
    for x in range(C-1,1,-1):
        room[up][x]=room[up][x-1]
    room[up][1]=0
    for y in range(down+1,R-1,1):
        room[y][0]=room[y+1][0]
    for x in range(0, C-1, 1):
        room[R-1][x]=room[R-1][x+1]
    for y in range(R-1, down-1, -1):
        room[y][C-1]=room[y-1][C-1]
    for x in range(C-1,1,-1):
        room[down][x]=room[down][x-1]
    room[down][1]=0

for _ in range(T):
    change=[[0]*C for _ in range(R)]
    for i in range(R):
        for j in range(C):
            count=0
            if room[i][j]==0 or room[i][j]==-1:
                if room[i][j]==-1:
                    purifier.append(i)
                continue
            for k in range(4):
                nx=i+dx[k]
                ny=j+dy[k]
                if nx<0 or ny<0 or nx>R-1 or ny>C-1 or room[nx][ny]==-1:
                    continue
                change[nx][ny]+=room[i][j]//5
                count+=1
            change[i][j]+=-((room[i][j]//5)*count)
    for i in range(R):
        for j in range(C):
            room[i][j]+=change[i][j]
    cleaner()

for i in range(R):
    for j in range(C):
        if room[i][j]==-1:
            continue
        sum+=room[i][j]
print(sum)


##너무 힘겨웠따!!!!! 공청기 옮기는 부분 적용이 너무 어려웠다.