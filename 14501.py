T=int(input())

for i in range(T):
    count=1
    N=int(input())
    array=[]
    result=[]
    for _ in range(N):
        array.append(tuple(map(int, input().split())))
    array.sort(key=lambda x:x[0])
    result.append(array[0])
    for j in range(1,N):
        if array[j][1]<array[0][1]:
            result.append(array[j])
    result.sort(key=lambda x:x[1])
    for j in range(1,len(result)):
        if result[j][0]<result[0][0]:
            count+=1
    print(count)
    

