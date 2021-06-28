k, s, n=input().split()
moves=[]
n=int(n)
krow=int(k[1])
kcol=int(ord(k[0]))-int(ord('A'))+1
srow=int(s[1])
scol=int(ord(s[0]))-int(ord('A'))+1
steps={'R': (0,1), 'L': (0,-1), 'B': (-1,0), 'T':(1,0), 'RT': (1,1), 'LT': (1,-1),
'RB': (-1,1), 'LB':(-1,-1)}

for i in range(n):
    moves.append(input())

for move in moves:
    next_krow=krow+steps[move][0]
    next_kcol=kcol+steps[move][1]
    if next_krow<1 or next_krow>8 or next_kcol<1 or next_kcol>8:
        continue
    if next_krow==srow and next_kcol==scol:
        next_srow=srow+steps[move][0]
        next_scol=scol+steps[move][1]
        if next_srow<1 or next_srow>8 or next_scol<1 or next_scol>8:
            continue
        srow=next_srow
        scol=next_scol
    krow=next_krow
    kcol=next_kcol

print(chr(kcol+ord('A')-1)+str(krow))
print(chr(scol+ord('A')-1)+str(srow))

## 문제좀 잘읽자!!!!!!!!!