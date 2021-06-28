def bsearch(dist):
    count=1
    start=houses[0]
    for i in range(1,n):
        if houses[i]-start>=dist:
            count+=1
            start=houses[i]
    if count>=c:
        return True
    else:
        return False

n, c=map(int, input().split())
houses=[]
for _ in range(n):
    houses.append(int(input()))
houses.sort()
left=1
right=houses[n-1]-houses[0]         ##최소 간격, 최대 간격 지정
res=0 ##최대값 저장

while left<=right:
    mid=(left+right)//2
    if bsearch(mid)==True:
        left=mid+1
        res=max(res, mid)
    else:
        right=mid-1
print(res)