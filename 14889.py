from itertools import combinations

N=int(input())
l=[x for x in range(N)]
S=[]
result=int(1e9)

for i in range(N):
    S.append(list(map(int, input().split())))

comb=list(combinations(l,N//2))
length=len(comb)//2

for i in range(length):
    start=0
    link=0
    for j in range(N//2):
        for k in range(j+1, N//2):
            start+=(S[comb[i][j]][comb[i][k]]+S[comb[i][k]][comb[i][j]])
    temp=[x for x in l if x not in comb[i]]
    for j in range(N//2):
        for k in range(j+1, N//2):
            link+=(S[temp[j]][temp[k]]+S[temp[k]][temp[j]])
    result=min(result, abs(start-link))

print(result)


