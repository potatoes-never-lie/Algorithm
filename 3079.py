N, M=map(int, input().split())
T=[]

for _ in range(N):
    T.append(int(input()))
T.sort()

start=1
end=T[-1]*M
result=end

while start<=end:
    mid=(start+end)//2
    total=0
    for i in T:
        total+=(mid//i)
    if total>=M:
        result=min(result,mid)
        end=mid-1
    else:
        start=mid+1

print(result)