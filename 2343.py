n, m=map(int, input().split())
array=list(map(int, input().split()))

left=max(array)
right=sum(array)

while left<=right:
    oneset=0
    count=0
    mid=(left+right)//2
    for i in array:
        if oneset+i>mid:
            oneset=0
            count+=1
        oneset+=i
    if oneset>0:
        count+=1
    if count>m:
        left=mid+1  
    else:
        right=mid-1

print(left)