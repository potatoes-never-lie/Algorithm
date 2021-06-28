n=int(input())
jusawi=list(map(int, input().split()))
sjusawi=sorted(jusawi)
one=sjusawi[0]
twolist=[]
threelist=[]
for i in range(6):
    for j in range(i+1,6):
        if (i==0 and j==5) or (i==1 and j==4) or (i==2 and j==3):
            continue
        twolist.append(jusawi[i]+jusawi[j])

two=min(twolist)

threelist.append(jusawi[0]+jusawi[1]+jusawi[2])
threelist.append(jusawi[0]+jusawi[2]+jusawi[4])
threelist.append(jusawi[0]+jusawi[4]+jusawi[3])
threelist.append(jusawi[0]+jusawi[3]+jusawi[1])
threelist.append(jusawi[5]+jusawi[1]+jusawi[3])
threelist.append(jusawi[5]+jusawi[1]+jusawi[2])
threelist.append(jusawi[5]+jusawi[3]+jusawi[4])
threelist.append(jusawi[5]+jusawi[4]+jusawi[2])
three=min(threelist)
if n==1:
    arr=sjusawi[:5]
    print(sum(arr))

else:
    result=one*(((n-2)*(n-2)*1)+((n-2)*(n-1)*4))
    result+=two*((4*(n-2))+(4*(n-1)))
    result+=(4*three)
    print(result)

##계산식 세운 후 이웃한 면 찾아서 더해주는게 포인트. 무조건 정렬이 아님@@!!!
