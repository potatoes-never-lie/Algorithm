states=[]
rotates=[]
states.append('')
for i in range(4):
    states.append(input())
n=int(input())
for i in range(n):
    rotates.append(tuple(map(int, input().split())))


def move(pos, direction):
    if direction==1:    ##시계방향
            states[pos]=str(states[pos][7])+str(states[pos][:7])
    elif direction==-1:
            states[pos]=str(states[pos][1:])+str(states[pos][0])
            
for rotate in rotates:
    directions=[0,0,0,0,0] 
    pos=rotate[0]               #pos는 회전시킨 톱니바퀴 번호
    directions[pos]=rotate[1]
    if pos==1:
        if states[1][2]!=states[2][6]:
            directions[2]=-directions[1]
        if directions[2]!=0 and states[2][2]!=states[3][6]:
            directions[3]=-directions[2]
        if directions[3]!=0 and states[3][2]!=states[4][6]:
            directions[4]=-directions[3]
    elif pos==2:
        if states[1][2]!=states[2][6]:
            directions[1]=-directions[2]
        if states[2][2]!=states[3][6]:
           directions[3]=-directions[2]
        if directions[3]!=0 and states[3][2]!=states[4][6]:
            directions[4]=-directions[3]
    elif pos==3:
        if states[3][2]!=states[4][6]:
            directions[4]=-directions[3]
        if states[2][2]!=states[3][6]:
            directions[2]=-directions[3]
        if directions[2]!=0 and states[1][2]!=states[2][6]:  
            directions[1]=-directions[2] 
    else:
        if states[3][2]!=states[4][6]:
            directions[3]=-directions[4]
        if directions[3]!=0 and states[2][2]!=states[3][6]:
            directions[2]=-directions[3]
        if directions[2]!=0 and states[1][2]!=states[2][6]:
            directions[1]=-directions[2]

    for i in range(1,5):
        move(i, directions[i])

result=int(states[1][0])+(int(states[2][0])*2)+(int(states[3][0])*4)+(int(states[4][0])*8)
print(result)

## 해결하는데 너무 힘들었따 ㅜㅜㅜ 한번에 바꿔주는게 포인트였다.. 난 계속 바꾸면서 체크했는데 그건 잘못된 방법이었다..
## 이웃이 다르고 이웃이 회전하는 이 2가지 경우를 모두 만족해야 움직인다라는 포인트를 아는게 중요..