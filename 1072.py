x, y=map(int, input().split())
z=int(100 * float(y)/float(x))

start=0
end=2000000001

def binary_search(x,y,z,start,end):
    while start<=end:
        mid=(start+end)//2
        newz=int(100 * float(y+mid)/float(x+mid))
        if newz>z:  ##승률 변할 경우
            end=mid-1
            result=mid
        else:
            start=mid+1
    print(result)

if z>=99:
    print(-1)
else:   
    binary_search(x,y,z,start,end)
##문제잘읽자,,,!!!!! 입력만 10억 이하인 거고.. 전체게임수는 언제든지 10억 넘을수있다는사실

