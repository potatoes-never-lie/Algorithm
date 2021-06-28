arr=input().split('-')
l=[]
for char in arr:
    temp=char.split('+')
    num=0
    for i in temp:
        num+=int(i)
    l.append(num)

result=l[0]
for i in range(1,len(l)):
    result-=l[i]
print(result)

#split 함수 이용하면 이렇게 간단하게 해결할 수 있는걸..왜이렇게 어렵게 했냐고!!!!!!!!!
#split 함수 이용해서 - 기준으로 식들 착착 모으고, 그 식들 중에 + 들어간거 있으면 다시 +로 스플릿해서 요소들끼리 더해서
#배열에 넣으면 되는거였다.... 조건 에 따른 처리 생각하느라 머리터질뻔^^ 내 능력 부족이겠찌머.