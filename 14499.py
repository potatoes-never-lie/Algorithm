dices={1:(3,4,5,2), 2:(3,4,1,6), 3:(6,1,5,2), 4:(1,6,5,2), 5:(3,4,6,1), 6:(3,4,2,5)}
#동서남북-(bottom to 동,서,남,북 plane)

c={1:0, 2:1, 4:2, 3:3}
dices_value=[0,0,0,0,0,0,0]
across={1:6, 2:5, 3:4, 4:3, 5:2, 6:1}

N, M, x, y, K=map(int, input().split())
board=[]
dx=[0,0,0,-1,1]
dy=[0,1,-1,0,0]
bottom=6
for _ in range(N):
    board.append(list(map(int, input().split())))
commands=list(map(int, input().split()))

for i in range(K):
    x, y=x+dx[commands[i]],y+dy[commands[i]]
    if x<0 or y<0 or x>=N or y>=M:
        x,y=x-dx[commands[i]],y-dy[commands[i]]
        continue
    pos=c[commands[i]]
    bottom=dices[bottom][pos]
    if board[x][y]==0:
        board[x][y]=dices_value[bottom]
    else:
        dices_value[bottom]=board[x][y]
        board[x][y]=0
    print(dices_value[across[bottom]])
    
#보류!!