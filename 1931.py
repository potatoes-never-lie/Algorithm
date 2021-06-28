N=int(input())
array=[]
count=1
for i in range(N):
    start, end=map(int, input().split())
    array.append((start,end))

array.sort(key=lambda x: (x[1], x[0]))
meeting=array[0]

for i in range(1,len(array)):
    if meeting[1]<=array[i][0]:
        count+=1
        meeting=array[i]
print(count)