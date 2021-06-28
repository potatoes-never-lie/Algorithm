N, M=map(int, input().split())
trees=list(map(int, input().split()))
start=1
end=2000000000
result=0

while start<=end:
    mid=(start+end)//2
    total=0
    for tree in trees:
        if tree>mid:
            total+=(tree-mid)
    if total>=M:
        result=max(result,mid)
        start=mid+1
    else:
        end=mid-1

print(result)