a=[2,3,3,4,6,8,9]

start=0
end=6
target=3

while start<=end:
    mid=(start+end)//2
    if a[mid]==target:
        print(mid)
        break
    elif a[mid]>target:
        end=mid-1
    else:
        start=mid+1
    

    