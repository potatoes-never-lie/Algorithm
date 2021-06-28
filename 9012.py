T=int(input())
array=[]
result=[]
for i in range(T):
    array.append(list(input()))

for i in range(T):
    right, left=[], []
    for j in range(len(array[i])):
        item=array[i].pop()
        if item==')':
            right.append(item)
        else:
            left.append(item)
            if len(right)!=0:
                left.pop()
                right.pop()
    if len(left)==0 and len(right)==0:
        print("YES")
    else:
        print("NO")