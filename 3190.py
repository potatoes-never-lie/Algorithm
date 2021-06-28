N=int(input())
K=int(input())
apples=[]
changes={}
second=0
positions={(0,1):((-1,0),(1,0)), (1,0):((0,1),(0,-1)),(0,-1):((1,0),(-1,0)),(-1,0):((0,-1),(0,1))}
dx,dy=0,1
body=[(1,1)]

for i in range(K):
    apples.append(tuple(map(int, input().split())))

L=int(input())
for i in range(L):
    X, C=input().split()
    changes[int(X)]=C

while True:
    second+=1
    x,y=body[-1]  ##x,y가 머리
    isApple=False
    x, y=x+dx, y+dy

    if x<1 or x>N or y<1 or y>N:
        break
    if (x,y) in body:
        break

    for ax, ay in apples:
        if x==ax and y==ay:
            isApple=True
            apples.remove((ax,ay))

    if isApple==False:
        body.pop(0)
    body.append((x,y))

    if second in changes.keys():
        if changes[second]=='L':
            dx, dy=positions[(dx,dy)][0]
        elif changes[second]=='D':
            dx, dy=positions[(dx,dy)][1]

print(second)