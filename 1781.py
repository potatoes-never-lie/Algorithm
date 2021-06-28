import heapq

n=int(input())
hq=[]
ans=0
day=1

for _ in range(n):
    heapq.heappush(hq, tuple(map(int, input().split())))

while hq:
    x=heapq.heappop(hq)
    print(x)
        
