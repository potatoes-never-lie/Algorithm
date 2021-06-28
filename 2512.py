n=int(input())
arr=list(map(int, input().split()))
m=int(input())
arr.sort()
result=0

if m>=sum(arr):
    print(arr[-1])
else:
    left=0
    right=arr[-1]
    while left<=right:
        mid=(left+right)//2
        sum=0
        for budget in arr:
            if budget>=mid:
                sum+=mid
            else:
                sum+=budget
        if sum<=m:
            left=mid+1
            result=max(result,mid)
        else:
            right=mid-1
    print(result)