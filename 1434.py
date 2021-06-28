list1=[]
storage=0
usage=0

for i in range(3):
    list1.append(list(map(int, input().split())))

for i in list1[1]:
    storage+=i

for i in list1[2]:
    usage+=i

print(storage-usage)

# 이렇게하는 것보단 list의 sum 함수 이용한느게 훨배 낫다. 그럼 게산더간단함.