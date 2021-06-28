from collections import deque

def D(n):
    if n*2>9999:
        return (n*2)%10000
    return n*2

def S(n):
    if n==0:
        return 9999
    return n-1

def L(n):
    d1=n//1000
    d2=(n%1000)//100
    d3=((n%1000)%100)//10
    d4=(((n%1000)%100)%10)
    return ((d2*10+d3)*10+d4)*10+d1

def R(n):
    d1=n//1000
    d2=(n%1000)//100
    d3=((n%1000)%100)//10
    d4=(((n%1000)%100)%10)
    return ((d4*10+d1)*10+d2)*10+d3

T=int(input())
array=[]
DSLR=["D","S","L","R"]
for _ in range(T):
    array.append(list(map(int, input().split())))

def bfs(start, target):
    queue=deque([start])
    traces[start]="0"
    while queue:
        x=queue.popleft()
        if x==target:
            return traces[x][1:]
        i=-1
        for nx in (D(x), S(x), L(x), R(x)):
            i+=1
            if traces[nx]!="":
                continue
            traces[nx]=traces[x]+DSLR[i]
            queue.append(nx)

for i in range(T):
    traces=[""]*10000
    print(bfs(array[i][0], array[i][1]))
