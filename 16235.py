from collections import deque

N, M, K=map(int, input().split())
yangbun=[[5]*N for _ in range(N)]
trees={(i,j): deque() for i in range(N) for j in range(N)}
plus=[]
dx=[-1,-1,-1,0,0,1,1,1]
dy=[-1,0,1,-1,1,-1,0,1]
result=0
for _ in range(N):
    plus.append(list(map(int, input().split())))

for _ in range(M):
    x, y, age=map(int, input().split())
    trees[(x-1,y-1)].append(age)

def spring():
    died=[]
    for i in range(N):
        for j in range(N):
            newq=[]
            flag=False
            while trees[(i,j)]:
                flag=True
                age=trees[(i,j)][0]
                if yangbun[i][j]-age>=0:
                    yangbun[i][j]-=age
                    newq.append(age+1)
                else:
                    died.append((i,j,age))
                trees[(i,j)].popleft()
            if flag:
                trees[(i,j)]=deque(newq)        
    return died

def summer(died):
    for x,y,age in died:
        yangbun[x][y]+=(age//2)

def autumn():
    for i in range(N):
        for j in range(N):
            if trees[(i,j)]:
                for k in range(len(trees[(i,j)])):
                    age=trees[(i,j)][k]
                    if age%5==0:
                        for e in range(8):
                            ni=i+dx[e]
                            nj=j+dy[e]
                            if ni<0 or nj<0 or ni>=N or nj>=N:
                                continue
                            trees[(ni,nj)].appendleft(1)
                

def winter():
    for i in range(N):
        for j in range(N):
            yangbun[i][j]+=plus[i][j]

for i in range(K):
    d=spring()
    summer(d)
    autumn()
    winter()

for i in range(N):
    for j in range(N):
        result+=len(trees[(i,j)])

print(result)
