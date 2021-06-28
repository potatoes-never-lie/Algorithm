from itertools import permutations

n=int(input())
op=[]
result=[]
array=list(map(int, input().split()))
temp=list(map(int, input().split()))
for i in range(4):
    if i==0:
        for _ in range(temp[i]):
            op.append('+')
    elif i==1:
        for _ in range(temp[i]):
            op.append('-') 
    elif i==2:
        for _ in range(temp[i]):
            op.append('*') 
    elif i==3:
        for _ in range(temp[i]):
            op.append('//') 

op=set(permutations(op,n-1))
for i in op:
    res=array[0]
    for j in range(1,n):
        if i[j-1]=='+':
            res+=array[j]
        elif i[j-1]=='-':
            res-=array[j]
        elif i[j-1]=='*':
            res*=array[j]
        elif i[j-1]=='//':
            if res<0 and array[j]>0:
                res=(res*(-1)//array[j])*-1
            else:           
                res//=array[j]
    result.append(res)

print(max(result))
print(min(result))
