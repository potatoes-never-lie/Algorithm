chess=[]
l=[]
count=0
for _ in range(8):
    chess.append(input())

for i in range(8):
    if i%2==0:
        l=[0,2,4,6]
    else:
        l=[1,3,5,7]
    for j in l:
        if chess[i][j]=='F':
            count+=1

print(count)
