from itertools import combinations

L, C=map(int, input().split())
chars=input().split()
mo=[]
ja=[]
s=set()

def convert(s): 
    new = ""  
    for x in s: 
        new += x  
    return new 

for char in chars:
    if char in ['a','e','i','o','u']:
        mo.append(char)
    else:
        ja.append(char)

twoja=list(combinations(ja, 2))

for m in mo:
    for j1, j2 in twoja:
        l=[x for x in chars if x not in [m,j1,j2]]
        rest=list(combinations(l, L-3))
        for k in rest:
            k+=(m,j1,j2)
            k=sorted(k)
            s.add(convert(k))

for i in sorted(s):
    print(i)
            