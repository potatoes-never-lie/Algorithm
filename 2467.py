n=int(input())
liquids=list(map(int, input().split()))

left=0
right=2000000000

while left<=right:
    mid=(left+right)//2
    isClose=False
    for i in range(n):
        start, end=i+1, n-1
        while start<=end:
            mid2=(start+end)//2
            if abs(liquids[i]+liquids[mid2])<=mid:
                isClose=True
                l=(i,mid2)
                break
            else:
                if liquids[i]>=0 and liquids[mid2]>=0:
                    end=mid2-1
                elif liquids[i]<0 and liquids[mid2]<0:
                    start=mid2+1
                elif liquids[i]<0 and liquids[mid2]>=0:
                    if abs(liquids[i])>=abs(liquids[mid2]):
                        start=mid2+1
                    else:
                        end=mid2-1
        if isClose==True:
            break
    if isClose==True:
        right=mid-1
    else:
        left=mid+1

print(str(liquids[l[0]])+" "+str(liquids[l[1]]))