n=int(input())
k=int(input())

left=1
right=k

while left<=right:
    count=0
    mid=(left+right)//2
    for i in range(1,n+1):
        count+=min(mid//i, n)
    if count<k:
        left=mid+1
    else:
        right=mid-1
        result=mid

print(result)