from itertools import combinations

N, S=map(int, input().split())
L=list(map(int, input().split()))
count=0

for i in range(N):
    cb=list(combinations(L,i+1))
    for item in cb:
        if sum(item)==S:
            count+=1
print(count)