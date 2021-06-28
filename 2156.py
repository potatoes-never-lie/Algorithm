n = int(input())
d=[0]*n
array=[]
for _ in range(n):
    array.append(int(input()))

for i in range(n):
    if i==0:
        d[0]=array[0]
    elif i==1:
        d[1]=d[0]+array[1]
    elif i==2:
        d[2]=max(array[0], array[1])+array[2]
    else:
        d[i]=max(max(d[:i-2])+array[i-1], max(d[:i-1]))+array[i]

print(max(d))